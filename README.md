# UIAutolayout
UI控件多屏适配

根据不同屏幕的尺寸比例进行等比例缩放处理，即重写CGRectMake方法，即CGRectMakeAutolayout。

使用示例
~~~javascript
// 方法1
UIImageView *imageViewTmp = [[UIImageView alloc] initWithFrame:CGRectMakeAutolayout(10.0, 10.0, 30.0, 30.0, YES, YES)];
 [self.view addSubview:imageViewTmp];
imageViewTmp.backgroundColor = [UIColor colorWithWhite:0.0 alpha:0.2];
imageViewTmp.contentMode = UIViewContentModeScaleAspectFit;
~~~
~~~javascript
// 方法2
#define sizeImage GetHeightAutolayout(40.0)
UIImageView *imageView = [[UIImageView alloc] initWithFrame:CGRectMake(10.0, 10.0, sizeImage, sizeImage)];
 [self.view addSubview:imageView];
imageView.backgroundColor = [UIColor colorWithWhite:0.0 alpha:0.2];
imageView.contentMode = UIViewContentModeScaleAspectFit;
~~~
