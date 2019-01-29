//
//  VideoRenderer.swift
//  SmartPlayer
//
//  Created by Rasul on 29/01/2019.
//  Copyright © 2019 rasultataev. All rights reserved.
//

import Foundation
import Metal
import MetalKit

final class VideoRenderer: NSObject {
    private let device: MTLDevice
    private let commandQueue: MTLCommandQueue
    private let computePipeline: MTLComputePipelineState
    
    
    init(device: MTLDevice) throws {
        self.device = device
        self.commandQueue = device.makeCommandQueue()!
        
        let library = device.makeDefaultLibrary()!
        let computeFunc = library.makeFunction(name: "convertToRgbAndShow")!
        
        guard let computePipelineState = try? device.makeComputePipelineState(function: computeFunc) else {
            assertionFailure("makeComputePipelineState returned nil")
            throw NSError(domain: "Metal-Related", code: 1001, userInfo: [kCFErrorLocalizedDescriptionKey as String: "makeComputePipelineState returned nil"])
        }
        
        self.computePipeline = computePipelineState
    }
    
    
}
