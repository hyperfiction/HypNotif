class ApplicationMain
{
	
	public static function main()
	{
		nme.Lib.setPackage("Hyperfiction", "hypertest", "fr.hyperfiction.Tests", "1.0.0");
		
		
		nme.display.Stage.shouldRotateInterface = function(orientation:Int):Bool
		{
			
			if (orientation == nme.display.Stage.OrientationLandscapeLeft || orientation == nme.display.Stage.OrientationLandscapeRight)
			{
				return true;
			}
			return false;
			
		}
		
		nme.Lib.create(function()
			{
				if (1024 == 0 && 768 == 0)
				{
					nme.Lib.current.stage.align = nme.display.StageAlign.TOP_LEFT;
					nme.Lib.current.stage.scaleMode = nme.display.StageScaleMode.NO_SCALE;
				}
				
				var hasMain = false;
				
				for (methodName in Type.getClassFields(TestTouch))
				{
					if (methodName == "main")
					{
						hasMain = true;
						break;
					}
				}
				
				if (hasMain)
				{
					Reflect.callMethod (TestTouch, Reflect.field (TestTouch, "main"), []);
				}
				else
				{
					nme.Lib.current.addChild(cast (Type.createInstance(TestTouch, []), nme.display.DisplayObject));	
				}
			},
			1024, 768,
			60,
			0xFFFFFF,
			(true ? nme.Lib.HARDWARE : 0) |
			(true ? nme.Lib.RESIZABLE : 0) |
			(1 == 4 ? nme.Lib.HW_AA_HIRES : 0) |
			(1 == 2 ? nme.Lib.HW_AA : 0),
			"HyperTest(s)"
		);
		
	}
	
	
	public static function getAsset(inName:String):Dynamic
	{
		
		if (inName == "assets/logo.png")
		{
			
			return nme.Assets.getBitmapData ("assets/logo.png");
			
		}
		
		if (inName == "assets/nme.svg")
		{
			
			return nme.Assets.getBytes ("assets/nme.svg");
			
		}
		
		return null;
	}
	
}