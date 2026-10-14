static const char BEHAVIOR_MANIFEST[]=R"MSD({
  "schema": 1,
  "library_version": 7,
  "param_types": {
    "unit_key": "单位稳定键；internal 为 true 时须为内部单位（internal_only），为 false 时须为可选单位",
    "rational": "[分子, 分母] 正整数倍率",
    "int": "整数，min/max 含端点",
    "int_list": "整数列表；length 为固定长度，或以 min_length/max_length 给出长度范围；min/max 作用于每个元素",
    "rational_list": "[分子, 分母] 列表；min_length/max_length 为长度范围，min/max 作用于每个元素",
    "sound_key": "音效稳定键（content.json 或模组 content.sounds 中登记，可见范围与单位动作脚本 op23 相同）",
    "sound_list": "音效稳定键列表；min_length/max_length 为长度范围"
  },
  "behaviors": [
    {
      "name": "build_structure",
      "version": 1,
      "base_classes": [
        77
      ],
      "params": {
        "structure": {
          "type": "unit_key",
          "required": true,
          "internal": true
        },
        "construction_time_multiplier": {
          "type": "rational",
          "default": [
            1,
            1
          ],
          "min": [
            1,
            100
          ],
          "max": [
            100,
            1
          ]
        }
      },
      "doc": {
        "ZS": "工兵类单位：出击后修筑指定的内部单位（如召唤箱）。修筑时间按倍率调整（状态词 38，向上取整）；兵种浏览、出兵格与属性面板显示修筑完成后的单位。",
        "EN": "Builder units construct the given internal unit after deployment. The construction time (status word 38, rounded up) is scaled by the multiplier. The unit viewer, deck card and status panel show the finished structure."
      }
    },
    {
      "name": "summon_units",
      "version": 1,
      "base_classes": [
        64
      ],
      "params": {
        "unit": {
          "type": "unit_key",
          "required": true,
          "internal": false
        },
        "interval_multiplier": {
          "type": "rational",
          "default": [
            1,
            1
          ],
          "min": [
            1,
            100
          ],
          "max": [
            100,
            1
          ]
        },
        "interval_additional_multiplier": {
          "type": "rational",
          "default": [
            1,
            1
          ],
          "min": [
            1,
            100
          ],
          "max": [
            100,
            1
          ]
        }
      },
      "doc": {
        "ZS": "召唤箱类单位：按计量周期召唤指定的可选单位。首次计量（状态词 38）与后续间隔（状态词 39，含计量零值的一帧）先按 interval_multiplier、再按 interval_additional_multiplier 调整。",
        "EN": "Summoning structures periodically summon the given selectable unit. The first gauge (status word 38) and later intervals (status word 39, including the zero-gauge frame) are scaled by interval_multiplier, then by interval_additional_multiplier."
      }
    },
    {
      "name": "spawn_child_unit",
      "version": 1,
      "base_classes": [
        159,
        163
      ],
      "params": {
        "unit": {
          "type": "unit_key",
          "required": true,
          "internal": true
        }
      },
      "doc": {
        "ZS": "投放与架设类单位：出击时由原生流程生成指定的内部单位（伞兵运输、迫击炮架设）。属性面板显示内部单位的数值。",
        "EN": "Deployer units (paratrooper drop, mortar emplacement) spawn the given internal unit through the native flow. The status panel shows the internal unit's values."
      }
    },
    {
      "name": "para_drop_transform",
      "version": 1,
      "base_classes": [
        160
      ],
      "params": {
        "landing_unit": {
          "type": "unit_key",
          "required": true,
          "internal": false
        }
      },
      "doc": {
        "ZS": "空降中的内部单位：落地后转换为指定的可选单位（替代原生固定的 UnitID 45）。",
        "EN": "Falling paratrooper (internal unit) turns into the given selectable unit on landing, replacing the native fixed UnitID 45."
      }
    },
    {
      "name": "insect_swarm_release",
      "version": 1,
      "base_classes": [
        61
      ],
      "params": {},
      "doc": {
        "ZS": "地面木乃伊类单位改用垂吊木乃伊（UnitID 157）的发射动作：攻击时释放虫群。虫群脚本、伤害与距离由单位的精灵描述符与攻击参数决定。",
        "EN": "Ground mummy units use the hanging mummy's (UnitID 157) shot action and release an insect swarm. Swarm scripts, damage and range come from the unit's sprite descriptor and attack parameters."
      }
    },
    {
      "name": "recovery_slot",
      "version": 1,
      "base_classes": [
        61
      ],
      "requires_fields": [
        "sprite_descriptor"
      ],
      "params": {
        "animation": {
          "type": "int",
          "required": true,
          "min": 0,
          "max": 255
        }
      },
      "doc": {
        "ZS": "受击后的恢复动作改用精灵描述符中的指定动画槽（原生固定为槽 26）；用于自定义描述符把槽 26 另作他用的情形。",
        "EN": "The recovery animation after being knocked back uses the given sprite-descriptor slot instead of the native slot 26, for descriptors that use slot 26 for something else."
      }
    },
    {
      "name": "flame_burst_interruptible",
      "version": 1,
      "base_classes": [
        3
      ],
      "requires_fields": [
        "sprite_descriptor"
      ],
      "params": {
        "flame_start_tick": {
          "type": "int",
          "required": true,
          "min": 0,
          "max": 255
        },
        "flame_ticks": {
          "type": "int",
          "required": true,
          "min": 6,
          "max": 200
        },
        "alternate_knockback_animation": {
          "type": "int",
          "required": true,
          "min": 0,
          "max": 255
        },
        "ending_bullet_animations": {
          "type": "int_list",
          "required": true,
          "length": 4,
          "min": 0,
          "max": 255
        }
      },
      "doc": {
        "ZS": "坦克类单位的绝招喷火：喷火阶段受击时，按已喷出的时长改用收尾受击动画（alternate_knockback_animation 起 5 个槽），并由收尾弹体动画完成最后一次判定（ending_bullet_animations 依次对应起始段三组与标准收尾）。",
        "EN": "Tank-class special flame attack. When knocked back during the flame, the unit switches to an ending knockback animation chosen by elapsed flame time (5 slots starting at alternate_knockback_animation), and an ending bullet animation performs the final hit (ending_bullet_animations: three early-phase groups and the standard ending)."
      }
    },
    {
      "name": "single_knockback_per_special",
      "version": 1,
      "base_classes": [
        3
      ],
      "requires_behaviors": [
        "flame_burst_interruptible"
      ],
      "params": {},
      "doc": {
        "ZS": "同一次绝招的喷火对同一目标最多击退一次。",
        "EN": "One special attack's flame knocks back the same target at most once."
      }
    },
    {
      "name": "ground_special_attack",
      "version": 1,
      "base_classes": [
        3
      ],
      "params": {},
      "doc": {
        "ZS": "坦克类单位的绝招状态（50）每帧沿用原生冲刺单位的地形移动流程，坡地上冲刺不悬空。",
        "EN": "During the special attack state (50), tank-class units use the native dash units' terrain movement every frame, so dashes follow slopes."
      }
    },
    {
      "name": "retained_special_weapon",
      "version": 1,
      "base_classes": [
        16,
        17,
        18,
        19,
        96,
        97,
        98,
        99,
        344,
        362
      ],
      "params": {},
      "doc": {
        "ZS": "马可、塔玛、英里、菲欧及其胖形态、圣诞英里、圣诞菲欧类单位：首次绝招后保留强化武器，之后的远程普通攻击使用原生绝招参数组（伤害、命中与射程），并保持持枪动作；胖英里保留大激光。与原版十类角色的行为相同。",
        "EN": "Marco, Tarma, Eri, Fio, their fat forms, Christmas Eri and Christmas Fio class units keep the special weapon after the first special attack: later ranged normal attacks use the native special-attack parameter group (damage, hit and range) and keep the armed pose; Fat Eri keeps the large laser. Same behaviour as the ten stock characters."
      }
    },
    {
      "name": "hp_stage_animations",
      "version": 1,
      "base_classes": [
        313,
        182
      ],
      "requires_fields": [
        "sprite_descriptor"
      ],
      "params": {
        "thresholds": {
          "type": "rational_list",
          "required": true,
          "min_length": 1,
          "max_length": 6,
          "min": [
            1,
            10000
          ],
          "max": [
            1,
            1
          ]
        },
        "transitions": {
          "type": "int_list",
          "required": true,
          "min_length": 1,
          "max_length": 6,
          "min": 0,
          "max": 1
        },
        "rage_stage": {
          "type": "int",
          "default": 0,
          "min": 0,
          "max": 6
        },
        "rage_speed_multiplier": {
          "type": "rational",
          "default": [
            1,
            1
          ],
          "min": [
            1,
            100
          ],
          "max": [
            100,
            1
          ]
        },
        "rage_damage_multiplier": {
          "type": "rational",
          "default": [
            1,
            1
          ],
          "min": [
            1,
            100
          ],
          "max": [
            100,
            1
          ]
        }
      },
      "doc": {
        "ZS": "按生命分档换外观（僵尸类单位，基准为僵尸（青年））。thresholds 为各档的生命比例（由高到低，生命低于最大生命×该比例即进入该档）；第 k 档使用精灵描述符的槽 原生槽号+16k（槽 0–2、6、7、9–12），同一动作换档时保留播放位置。transitions 中为 1 的档位先经状态 80 播放该档的槽 12（过渡动作，可在脚本中生成掉落效果与音效）。rage_stage 档起移速与普攻、绝招伤害按倍率改变（狂暴）。雪地步兵类单位（基准 182，推雪球的小兵 W.SOLDIER）同样可用：只就地换档，transitions 须全为 0，不支持狂暴（该动作类不处理状态 80，出击即不被击退）。",
        "EN": "Zombie-class units (base: Zombie (Young Man)) change appearance by remaining HP. thresholds are HP fractions in descending order (HP below max HP times the fraction enters that stage). Stage k uses sprite-descriptor slot native slot + 16k (slots 0-2, 6, 7, 9-12); switching stages keeps the playback position of the same action. Stages marked 1 in transitions first play that stage's slot 12 through state 80 (a transition that can spawn drop effects and sounds from its script). From rage_stage on, move speed and normal/special damage change by the multipliers. Also available for snowball-soldier class units (base 182, W.SOLDIER): stages only switch in place, transitions must all be 0 and rage is not supported (that action class does not process state 80 and is never knocked back)."
      }
    },
    {
      "name": "no_knockback",
      "version": 1,
      "base_classes": [
        313
      ],
      "params": {},
      "doc": {
        "ZS": "受击时不进入击退（不检查击退计量），生命归零时照常倒下。",
        "EN": "The unit is never knocked back by hits (the knockback gauge is not checked); it still dies when HP reaches zero."
      }
    },
    {
      "name": "front_nearest_target",
      "version": 1,
      "base_classes": [
        313
      ],
      "params": {},
      "doc": {
        "ZS": "原生每帧按横坐标为两队各取最前单位，攻击距离、阻挡与移动限制只看对方最前单位；单位落到对方最前单位之后时距离为负，原生一直攻击而攻击框内没有敌人，与其重叠的对方单位也不能越过它移动。本单位（或以本单位为对方最前单位的对方单位）的对方最前单位中心位于其中心之后时，改以其前方最近的对方单位计算攻击距离、阻挡与移动限制；资格与次序同原生。前方没有对方单位时按原生的无对方单位处理。",
        "EN": "Natively each team's front unit is chosen by x position every frame, and attack distance, blocking and the movement limit only look at the opposing front unit; a unit that ends up behind that front unit gets a negative distance and keeps attacking an empty attack box, and opposing units overlapping it cannot move past it. When the opposing front unit's centre is behind this unit's centre (or behind an opposing unit whose front unit is this unit), attack distance, blocking and the movement limit use the nearest opposing unit in front instead, chosen with the native eligibility and ordering. With no opposing unit in front, the native no-enemy handling applies."
      }
    },
    {
      "name": "stage_knockback_animation",
      "version": 1,
      "base_classes": [
        313
      ],
      "requires_behaviors": [
        "hp_stage_animations"
      ],
      "params": {},
      "doc": {
        "ZS": "生命分档单位被击退时播放当前档的槽 14（槽 14+16k），不经槽 12 重播该档的过渡动作。原生在进入状态 80 时请求槽 12：生命已越过下一个带过渡的档位时仍播放过渡（槽 12+16k），否则为击退，改用槽 14+16k（原生 ZombieBrain 不使用槽 14）。滑行距离与时长由该脚本的 op7 与帧决定。不能与 no_knockback 同时使用。",
        "EN": "When a staged-HP unit is knocked back it plays the current stage's slot 14 (slot 14+16k) instead of replaying that stage's transition from slot 12. The native code requests slot 12 when entering state 80: if HP has crossed the next stage with a transition, the transition (slot 12+16k) still plays; otherwise it is a knockback and slot 14+16k is used (native ZombieBrain never uses slot 14). The slide distance and duration come from that script's op7 commands and frames. Cannot be combined with no_knockback."
      }
    },
    {
      "name": "armor_hit_sound",
      "version": 1,
      "base_classes": [
        313,
        182
      ],
      "requires_behaviors": [
        "hp_stage_animations"
      ],
      "params": {
        "sounds": {
          "type": "sound_list",
          "required": true,
          "min_length": 1,
          "max_length": 2
        },
        "until_stage": {
          "type": "int",
          "required": true,
          "min": 1,
          "max": 6
        }
      },
      "doc": {
        "ZS": "生命处于 until_stage 档之前（防具仍在）时，每次受击播放音效（两个音效时交替）。until_stage 为档数 + 1 时在所有档位都播放。",
        "EN": "While HP is above stage until_stage (the armor is still on), each hit plays the sound (two sounds alternate). With until_stage equal to the number of stages + 1 the sound plays in every stage."
      }
    },
    {
      "name": "kill_sound",
      "version": 1,
      "base_classes": [
        313
      ],
      "params": {
        "sound": {
          "type": "sound_key",
          "required": true
        }
      },
      "doc": {
        "ZS": "本单位的攻击使目标生命归零时播放音效。",
        "EN": "Plays the sound when this unit's attack brings a target's HP to zero."
      }
    },
    {
      "name": "throw_child_on_stage",
      "version": 1,
      "base_classes": [
        313
      ],
      "requires_behaviors": [
        "hp_stage_animations"
      ],
      "params": {
        "unit": {
          "type": "unit_key",
          "required": true,
          "internal": true
        },
        "stage": {
          "type": "int",
          "required": true,
          "min": 1,
          "max": 6
        },
        "release_tick": {
          "type": "int",
          "required": true,
          "min": 0,
          "max": 255
        }
      },
      "doc": {
        "ZS": "进入 stage 档时（该档须有过渡动作），在过渡动作的第 release_tick 帧投出指定的内部单位（以本单位等级生成，每个单位只投一次）。内部单位应为被投出的飞行单位（基准 160，thrown_flight 与 para_drop_transform）。",
        "EN": "When the unit enters stage (which must have a transition), it throws the given internal unit at frame release_tick of the transition (spawned at this unit's level, once per unit). The internal unit should be a thrown flying unit (base 160 with thrown_flight and para_drop_transform)."
      }
    },
    {
      "name": "thrown_flight",
      "version": 1,
      "base_classes": [
        160
      ],
      "requires_behaviors": [
        "para_drop_transform"
      ],
      "params": {
        "forward": {
          "type": "int",
          "default": 0,
          "min": -1000,
          "max": 1000
        },
        "height": {
          "type": "int",
          "default": 0,
          "min": 0,
          "max": 1000
        }
      },
      "doc": {
        "ZS": "被投出的飞行单位：从投出者位置前方 forward、高 height 处出发（世界坐标），不使用空降的固定起始高度；飞行轨迹由精灵描述符槽 8 的脚本（op7）决定，落地后转为 para_drop_transform 指定的单位。",
        "EN": "Thrown flying unit: starts forward and height (world units) from the thrower instead of the fixed paratrooper drop height; the flight path comes from the slot 8 script (op7) of its sprite descriptor, and it turns into the para_drop_transform unit on landing."
      }
    },
    {
      "name": "no_death_splash",
      "version": 1,
      "base_classes": [
        182
      ],
      "params": {},
      "doc": {
        "ZS": "雪地步兵类单位以爆炸属性（属性 2）被击毁时，原生 ZakoSnow 在状态 110 生成血色效果 0xff01，状态 110 与状态 100 只差这一项（两者都播放槽 13 并转入状态 140）。带此行为的单位按状态 100 处理，只播放本单位的死亡动作；火焰属性（状态 120）不变。",
        "EN": "When a snow-soldier-class unit is destroyed by an explosive attack (attribute 2), the native ZakoSnow code adds the red splash effect 0xff01 in state 110; that is the only difference from state 100 (both play slot 13 and move to state 140). Units with this behaviour are handled as state 100 and only play their own death animation; fire deaths (state 120) are unchanged."
      }
    }
  ]
}
)MSD";
