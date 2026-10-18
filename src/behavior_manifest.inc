static const char BEHAVIOR_MANIFEST[]=R"MSD({
  "schema": 1,
  "library_version": 10,
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
        },
        "base_clearance": {
          "type": "int",
          "default": 0,
          "min": 0,
          "max": 1000
        }
      },
      "doc": {
        "ZS": "被投出的飞行单位：从投出者位置前方 forward、高 height 处出发（世界坐标），不使用空降的固定起始高度；飞行轨迹由精灵描述符槽 8 的脚本（op7）决定，落地后转为 para_drop_transform 指定的单位。base_clearance 大于 0 时，飞行中前缘与敌方据点前缘的间距不小于该值（世界坐标）：将越过时停在该处并垂直落下，避免越过或嵌入敌方据点（2026-10-15 起被投出的小鬼为 16）。",
        "EN": "Thrown flying unit: starts forward and height (world units) from the thrower instead of the fixed paratrooper drop height; the flight path comes from the slot 8 script (op7) of its sprite descriptor, and it turns into the para_drop_transform unit on landing. With base_clearance above 0 the flying unit keeps at least that gap (world units) between its front edge and the enemy base front edge: when it would pass that point it stops there and drops straight down, so it never lands inside or behind the enemy base (16 for the thrown imp since 2026-10-15)."
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
    },
    {
      "name": "self_destruct_attack",
      "version": 1,
      "base_classes": [
        313
      ],
      "params": {
        "unmirrored_from_tick": {
          "type": "int",
          "default": -1,
          "min": -1,
          "max": 1000
        }
      },
      "doc": {
        "ZS": "自爆：进入攻击（状态 30/40）与特殊攻击（状态 50）时按原版 HOPPER MECHA（UnitID 39）的流程处理：普通攻击播放槽 8、特殊攻击播放槽 9，动作开始即不被选为目标、不阻挡、不能再发动绝招，动作播完后单位消失（不经死亡流程，对方不获得击毁奖励）；动作中不会被击退或打断。伤害取动作开始时的攻击组（普通攻击为词 22、特殊攻击为词 29），攻击框与音效写在这两个槽的脚本中。unmirrored_from_tick ≥ 0 时，攻击动作开始后第该 tick 起按素材原朝向绘制（不随队伍翻转，单位朝向与判定不变；用于带文字的爆炸图）。",
        "EN": "Self-destruct: attacks (states 30/40) and the special (state 50) follow the native HOPPER MECHA (UnitID 39) flow: the normal attack plays slot 8 and the special plays slot 9; from the start the unit is no longer targeted, does not block and cannot use its special, and it disappears when the animation ends (no death flow, no kill reward for the enemy). It cannot be knocked back or interrupted meanwhile. Damage uses the attack group active when the animation starts (word 22 for the normal attack, word 29 for the special); attack boxes and sounds go in the two slot scripts. With unmirrored_from_tick ≥ 0, from that tick of the attack animation the sprite is drawn in its original art direction (not flipped by team; the unit direction and hit boxes are unchanged), for explosion art that contains text."
      }
    },
    {
      "name": "ground_only_attack",
      "version": 1,
      "base_classes": [
        313
      ],
      "params": {},
      "doc": {
        "ZS": "本单位的攻击不命中空中单位（身体状态 NoTarget）与战场道具（UnitID 116、231、289、363），只打地面单位与据点。",
        "EN": "This unit's attacks never hit air units (body state NoTarget) or stage items (UnitID 116, 231, 289, 363); they hit ground units and the base only."
      }
    },
    {
      "name": "walk_shoot",
      "version": 1,
      "base_classes": [
        313
      ],
      "params": {
        "range": {
          "type": "int",
          "required": true,
          "min": 1,
          "max": 4000
        }
      },
      "doc": {
        "ZS": "行进射击：待机与行进（状态 10、20）的动作脚本中的 op22[弹体槽, 命中槽, x, y]（x、y 为素材坐标，同原生）在最近的敌方单位前缘距离不超过 range 时发射弹体，否则不发射；射击节奏由脚本中 op22 的位置决定。弹体的伤害、击退值、目标数、弹速与行程取近距参数组（词 15–21，可用 status_word_values 写入六个等级锚点），接触敌人后的啃咬照常使用普通攻击组。",
        "EN": "Shooting while walking: op22[bullet slot, hit slot, x, y] (art coordinates, as in native scripts) in the idle and walk scripts (states 10 and 20) fires a bullet when the nearest enemy front edge is within range, and does nothing otherwise; the firing rhythm comes from where op22 sits in the scripts. Bullet damage, knockback value, target count, speed and travel come from the short-range group (words 15–21, settable per level anchor with status_word_values); biting on contact uses the normal attack group as usual."
      }
    },
    {
      "name": "balloon_flight",
      "version": 1,
      "base_classes": [
        313
      ],
      "requires_behaviors": [
        "hp_stage_animations"
      ],
      "params": {
        "pop_distance": {
          "type": "int",
          "default": 16,
          "min": 0,
          "max": 1000
        },
        "launch_sound": {
          "type": "sound_key",
          "default": null
        }
      },
      "doc": {
        "ZS": "气球飞行：生命分档的第 0 档为飞行段（第 1 档须有过渡动作，即放手与落地）。飞行中不被选为目标、不阻挡、不被阻挡、不被击退，也不攻击任何敌人；高度由动作脚本的受击框（op3）与帧位置表达。前缘与敌方据点前缘的间距不超过 pop_distance、生命降到第 1 档或发动绝招时放手（主动放手时生命截到第 1 档以下），播放第 1 档的过渡动作后按地面单位行动，此后不再有绝招。launch_sound 为出场时的音效（可省略）。",
        "EN": "Balloon flight: HP stage 0 is the flying phase (stage 1 needs a transition: letting go and landing). While flying the unit is not targeted, does not block, is not blocked, is not knocked back and attacks nothing; its height comes from the hit boxes (op3) and frame positions in the scripts. It lets go when its front edge is within pop_distance of the enemy base front edge, when HP drops to stage 1, or when the special is used (letting go early cuts HP below stage 1); after the stage 1 transition it acts as a ground unit and has no special any more. launch_sound plays when it enters the field (optional)."
      }
    },
    {
      "name": "lob_blast",
      "version": 1,
      "base_classes": [
        221
      ],
      "params": {
        "blast_animation": {
          "type": "int",
          "required": true,
          "min": 0,
          "max": 255
        },
        "fuse_animation": {
          "type": "int",
          "required": true,
          "min": 0,
          "max": 255
        },
        "special_spread_first": {
          "type": "int",
          "default": 0,
          "min": 0,
          "max": 255
        },
        "special_spread_count": {
          "type": "int",
          "default": 0,
          "min": 0,
          "max": 16
        }
      },
      "doc": {
        "ZS": "炸药（原住民（鸟）类）：投出的弹体碰到敌人时立即播放 blast_animation（爆炸），落在地面时播放 fuse_animation（引信燃烧后爆炸），动画播完后消失（同原生迫击炮弹）；原生弹体碰到敌人或落地后直接消失、不爆炸。爆炸的攻击框、目标数（状态词 24/31）与音效写在这两个槽的脚本中，伤害与攻击属性取投出时的攻击组（普通攻击词 22/28，特殊攻击词 29/37）。special_spread_count 大于 0 时，动作脚本中 op22 的弹体槽在 special_spread_first 起连续 special_spread_count 个槽内的弹体（通常在特殊攻击中同时投出）以该槽为弹体动画，第 i 颗（1 起）落在 状态词 33（绝招弹体目的距离）× i / special_spread_count 处，即在射程内等距分布，射程随等级或倍率改变时落点随之改变；其余 op22 照旧，落在原生的普通攻击目的距离处（弹体动画为槽 26）。",
        "EN": "Dynamite (NATIVE(BIRD) class): a thrown projectile that touches an enemy plays blast_animation (explodes at once); one that lands on the ground plays fuse_animation (the fuse burns, then it explodes); it disappears when the animation ends, as the native mortar shell does. Native projectiles of this class disappear on contact or landing without exploding. Put the blast attack box, target count (words 24/31) and sounds in these two slots; damage and attack attribute come from the attack group active at the throw (normal: words 22/28, special: words 29/37). With special_spread_count > 0, op22 calls whose bullet slot lies in the special_spread_count slots starting at special_spread_first (usually thrown together in the special attack) use that slot as the projectile animation, and the i-th one (from 1) lands at word 33 (special projectile target distance) × i / special_spread_count: evenly spread up to the range, following any change of the range by level or multipliers. Other op22 calls keep the native path and land at the native normal-attack target distance (projectile slot 26)."
      }
    },
    {
      "name": "death_by_attribute",
      "version": 1,
      "base_classes": [
        221
      ],
      "params": {
        "explosion_animation": {
          "type": "int",
          "required": true,
          "min": 0,
          "max": 255
        },
        "fire_animation": {
          "type": "int",
          "required": true,
          "min": 0,
          "max": 255
        },
        "normal_variant_animation": {
          "type": "int",
          "default": 0,
          "min": 0,
          "max": 255
        },
        "explosion_variant_animation": {
          "type": "int",
          "default": 0,
          "min": 0,
          "max": 255
        },
        "fire_variant_animation": {
          "type": "int",
          "default": 0,
          "min": 0,
          "max": 255
        }
      },
      "doc": {
        "ZS": "按攻击属性区分死亡动作（原住民（鸟）类）：原生的死亡状态 100（普通）、110（爆炸属性击杀）、120（火焰属性击杀）都播放槽 12；带此行为时 110 改为 explosion_animation、120 改为 fire_animation，100 仍为槽 12（同叛军步兵等小兵的三种死亡）。动作播完后单位消失。三个 *_variant_animation 非 0 时为对应死亡的另一版本（通常只换死亡语音）：死亡时单位横坐标取整为奇数则播放该版本，偶数则播放前者；只由当时的位置决定，回放与联机时双方结果相同。",
        "EN": "Death animation by attack attribute (NATIVE(BIRD) class): the native death states 100 (normal), 110 (killed by an explosive attack) and 120 (killed by fire) all play slot 12. With this behaviour state 110 plays explosion_animation and 120 plays fire_animation, while 100 keeps slot 12, like the three deaths of rebel infantry. The unit disappears when the animation ends. A non-zero *_variant_animation is another version of that death (usually only the death voice differs): it plays when the unit's x coordinate, truncated to an integer, is odd at death, and the base version plays when it is even. The choice depends only on the position at that moment, so replays and both sides of an online match agree."
      }
    }
  ]
}
)MSD";
