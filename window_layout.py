"""Uniform viewport and pointer mapping for the expanded 16:9 surface."""
WIDTH, HEIGHT = 1280, 720

def fit_rect(width, height, canvas=(WIDTH, HEIGHT)):
    width, height = max(1, int(width)), max(1, int(height))
    cw,ch=canvas
    scale = min(width / cw, height / ch)
    w, h = max(1, round(cw * scale)), max(1, round(ch * scale))
    return (width - w) // 2, (height - h) // 2, w, h

def game_point(x, y, width, height, clamp=False):
    left, top, w, h = fit_rect(width, height)
    if not clamp and not (left <= x < left + w and top <= y < top + h):
        return None
    return max(0, min(WIDTH-0.1, (x-left)*WIDTH/w)), max(0, min(HEIGHT-0.1, (y-top)*HEIGHT/h))
