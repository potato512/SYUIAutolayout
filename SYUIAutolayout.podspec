Pod::Spec.new do |s|

  # 名称
  s.name         = "SYUIAutolayout"
  # 版本
  s.version      = "1.0.0"
  # 描述
  s.summary      = "SYUIAutolayout用于适配不同尺寸的iPhone机型。"
  s.description  = <<-DESC
                    通过SYUIAutolayout自动计算尺寸比例，以适配不同尺寸的iPhone机型。
                   DESC

  # 主页
  s.homepage     = "https://github.com/potato512/SYUIAutolayout"
  
  # 证书证明
  s.license      = "MIT"
  # s.license      = { :type => "MIT", :file => "FILE_LICENSE" }
 
  # 作者
  s.social_media_url   = "http://twitter.com/herman"
  s.author             = { "herman" => "zhangsy757@163.com" }
  
  # 仓库地址
  s.source       = { :git => "https://github.com/potato512/SYUIAutolayout.git", :tag => "#{s.version}" }
  # 库文件地址（相对于.podspec文件的路径）——重要
  s.source_files  = "SYUIAutolayout/DemoAutoSize/DemoAutoSize/SYUIAutoSiz/*.{h}"
  # 公开文件
  s.public_header_files = "SYUIAutolayout/DemoAutoSize/DemoAutoSize/SYUIAutoSiz/SYAutoSizeCGRect.h"
  # 静态库文件将s.ios.vendored_framework前的ios文件夹去掉
  # s.ios.vendored_framework   = 'PPSPrivateStaticLibrary.framework'

  # 是否支持ARC
  s.requires_arc = true

  # 支持版本
  s.platform     = :ios, "5.0"
  s.ios.deployment_target = '5.0'

  pch_AF = <<-EOS
#ifndef TARGET_OS_IOS
  #define TARGET_OS_IOS TARGET_OS_IPHONE
#endif
EOS
  s.prefix_header_contents = pch_AF
    
  # 依赖Framework
  # s.frameworks = 'Foundation', 'UIKit'

  # 依赖library，如sqllite等tbd结尾的
  # s.libraries = 'resolv'

  # 依赖第三库
  # s.dependency "JSONKit", "~ > 1.4"

end
