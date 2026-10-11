// SPDX-License-Identifier: GPL-3.0-or-later
package
{
   import flash.text.TextField;
   import flash.text.TextFormat;
   import flash.utils.getTimer;
   import survarium.controls.VictoryScreen;

   // Observe the native waiting state without fabricating a result or changing
   // its close/late-result handlers. Native setData hides syncImage on success.
   public class SrpResults
   {
      private var screen:VictoryScreen;
      private var notice:TextField;
      private var waitingSince:int = -1;

      public function SrpResults(owner:VictoryScreen)
      {
         screen=owner;
         notice=new TextField();
         notice.wordWrap=true; notice.multiline=true;
         notice.mouseEnabled=false; notice.selectable=false;
         notice.text="Match statistics have not arrived.\nYou can close this screen and return to Matches.";
         notice.visible=false;
         screen.addChild(notice);
      }

      public function tick():void
      {
         var waiting:Boolean=screen.parent!=null && screen.visible && screen.syncImage.visible;
         if(!waiting)
         {
            waitingSince=-1; notice.visible=false;
            return;
         }
         if(waitingSince<0) waitingSince=getTimer();
         if(getTimer()-waitingSince<15000) return;
         if(!notice.visible)
         {
            // Native localization initializes this field after construction.
            // Copy the populated field's style, not its empty initial format.
            var format:TextFormat=screen.loading_text.getTextFormat();
            format.align="center";
            notice.defaultTextFormat=format; notice.setTextFormat(format);
            notice.embedFonts=screen.loading_text.embedFonts;
         }
         notice.x=screen.loading_text.x;
         notice.y=screen.loading_text.y-30;
         notice.width=screen.loading_text.width;
         notice.height=120;
         screen.loading_text.visible=false;
         notice.visible=true;
      }

      public function dispose():void
      {
         if(notice.visible && screen.syncImage.visible) screen.loading_text.visible=true;
         if(notice.parent) notice.parent.removeChild(notice);
      }
   }
}
