Pod::Spec.new do |s|

  s.name         = "SYUIAutolayout"
  s.version      = "1.0.0"
  s.summary      = "SYUIAutolayout用于适配不同尺寸的iPhone机型。"
  s.description  = <<-DESC
                    通过SYUIAutolayout自动计算尺寸比例，以适配不同尺寸的iPhone机型。
                   DESC

  s.homepage     = "https://github.com/potato512/SYUIAutolayout"
  
  s.license      = { :type => "MIT", :file => "LICENSE" }
 
  s.author             = { "herman" => "zhangsy757@163.com" }
  
  s.source       = { :git => "https://github.com/potato512/SYUIAutolayout.git", :tag => "#{s.version}" }
  s.source_files  = "SYUIAutolayout/*.{h,m}"

  s.requires_arc = true

  s.platform     = :ios, "5.0"
  s.ios.deployment_target = '5.0'
  
end
