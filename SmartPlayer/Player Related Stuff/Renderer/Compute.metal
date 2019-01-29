//
//  Compute.metal
//  SmartPlayer
//
//  Created by Rasul on 29/01/2019.
//  Copyright © 2019 rasultataev. All rights reserved.
//

#include <metal_stdlib>
using namespace metal;


kernel void convertToRgbAndShow(texture2d<float, access::read> s_texture_y [[ texture(0) ]],
                                texture2d<float, access::read> s_texture_u [[ texture(1) ]],
                                texture2d<float, access::read> s_texture_v [[ texture(2) ]],
                                texture2d<float, access::write> outTexture [[ texture(3) ]],
                                uint2 gid [[ thread_position_in_grid ]])
{
    const float y = s_texture_y.read(gid).r;
    const float y = s_texture_u.read(gid).r - 0.5;
    const float y = s_texture_v.read(gid).r - 0.5;
    
    
    
//    highp float r = y +             1.402 * v;
//    highp float g = y - 0.344 * u - 0.714 * v;
//    highp float b = y + 1.772 * u;
    
    outTexture.write(colorAtPixel, gid);
}
