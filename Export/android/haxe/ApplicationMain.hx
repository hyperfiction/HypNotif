class ApplicationMain
{

	#if waxe
	static public var frame : wx.Frame;
	static public var autoShowFrame : Bool = true;
	#if nme
	static public var nmeStage : wx.NMEStage;
	#end
	#end
	
	public static function main()
	{
		#if nme
		nme.Lib.setPackage("Hyperfiction", "hypertest", "fr.hyperfiction.Tests", "1.0.0");
		
		#end
		
		#if waxe
		wx.App.boot(function()
		{
			
			frame = wx.Frame.create(null, null, "HyperTest(s)", null, { width: 1024, height: 768 });
			
			#if nme
			var stage = wx.NMEStage.create(frame, null, null, { width: 1024, height: 768 });
			#end
			
			TestNativeGestures.main();
			
			if (autoShowFrame)
			{
				wx.App.setTopWindow(frame);
				frame.shown = true;
			}
		});
		#else
		
		nme.Lib.create(function()
			{ 
				if (1024 == 0 && 768 == 0)
				{
					nme.Lib.current.stage.align = nme.display.StageAlign.TOP_LEFT;
					nme.Lib.current.stage.scaleMode = nme.display.StageScaleMode.NO_SCALE;
				}
				
				var hasMain = false;
				
				for (methodName in Type.getClassFields(TestNativeGestures))
				{
					if (methodName == "main")
					{
						hasMain = true;
						break;
					}
				}
				
				if (hasMain)
				{
					Reflect.callMethod (TestNativeGestures, Reflect.field (TestNativeGestures, "main"), []);
				}
				else
				{
					nme.Lib.current.addChild(cast (Type.createInstance(TestNativeGestures, []), nme.display.DisplayObject));	
				}
			},
			1024, 768, 
			60, 
			0xFFFFFF,
			(true ? nme.Lib.HARDWARE : 0) |
			(true ? nme.Lib.RESIZABLE : 0) |
			(false ? nme.Lib.BORDERLESS : 0) |
			(false ? nme.Lib.VSYNC : 0) |
			(false ? nme.Lib.FULLSCREEN : 0) |
			(1 == 4 ? nme.Lib.HW_AA_HIRES : 0) |
			(1 == 2 ? nme.Lib.HW_AA : 0),
			"HyperTest(s)"
			
		);
		#end
		
	}
	
	
	public static function getAsset(inName:String):Dynamic
	{
		#if nme
		
		if (inName == "assets/logo.png")
		{
			
			return nme.Assets.getBitmapData ("assets/logo.png");
			
		}
		
		if (inName == "assets/nme.svg")
		{
			
			return nme.Assets.getBytes ("assets/nme.svg");
			
		}
		
		return null;
		#end
	}
	
	
}
