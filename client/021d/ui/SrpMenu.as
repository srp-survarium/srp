// SPDX-License-Identifier: GPL-3.0-or-later
package
{
   import flash.display.MovieClip;
   import flash.display.Sprite;
   import flash.display.DisplayObject;
   import scaleform.clik.controls.Button;
   import scaleform.clik.events.ButtonEvent;
   import flash.events.KeyboardEvent;
   import flash.events.Event;
   import flash.external.ExternalInterface;
   import flash.text.TextField;
   import flash.text.TextFormat;
   import flash.utils.getTimer;

   public class SrpMenu extends Sprite
   {
      private static var player:String = "preview-" + int(Math.random()*1000000000);
      private var token:String = "m" + getTimer() + "-" + int(Math.random()*1000000000);
      private var sequence:int = 0;
      private var frames:int = 0;
      private var panel:Sprite;
      private var skin:SrvPlayerRanking;
      private var lobby:LobbyMenu;
      private var results:SrpResults;
      private var mainButton:Button;
      private var retryButton:Button;
      private var nativeTextStyle:TextFormat;
      private var nativeEmbeddedText:Boolean;
      private var shield:Sprite;
      private var content:Sprite;
      private var status:TextField;
      private var screen:String = "browser";
      private var pending:String = "";
      private var failedId:String = "";
      private var operation:String = "";
      private var requestBody:String = "";
      private var deadline:int = 0;
      private var refreshAt:int = 0;
      private var backgroundRead:Boolean = false;
      private var capabilities:Object;
      private var rooms:Array = [];
      private var room:Object;
      private var nameInput:TextField;
      private var capacityInput:TextField;
      private var mapIndex:int = 0;
      private var summaryMap:TextField;
      private static const PAGE_SIZE:int = 8;
      private var page:int = 0;
      private var identityRetry:Boolean = false;
      public var response:TextField;
      public var wireResponse:String = "";

      public static function install(root:MovieClip):void { root.addChild(new SrpMenu(root as LobbyMenu)); }
      public static function isOpen(root:MovieClip):Boolean
      {
         var menu:SrpMenu=root.getChildByName("srpMenu") as SrpMenu;
         return menu!=null && menu.panel.visible;
      }
      public static function closeOpen(root:MovieClip):Boolean
      {
         var menu:SrpMenu=root.getChildByName("srpMenu") as SrpMenu;
         if(menu==null || !menu.panel.visible) return false;
         menu.closeMenu(null); return true;
      }

      public function SrpMenu(owner:LobbyMenu)
      {
         super(); name = "srpMenu"; lobby=owner;
         results=new SrpResults(lobby.victory_screen);
         mainButton=lobby.statusPanel.playBtn;
         mainButton.addEventListener(ButtonEvent.CLICK,openMenu,false,1000);
         mainButton.label="Matches"; mainButton.enabled=true;
         // Reuse the stock Ranking window's actual frame and text styles.
         // Hide its ranking-specific controls; no ranking request is activated.
         skin=new SrvPlayerRanking(); panel=skin;
         nativeTextStyle=skin.txNickname.getTextFormat();
         nativeEmbeddedText=skin.txNickname.embedFonts;
         for(var i:int=0;i<skin.numChildren;i++)
         {
            var child:DisplayObject=skin.getChildAt(i);
            child.visible=i==0 || child==skin.txLabel || child==skin.btn_close || child==skin.btn_close2;
         }
         skin.txLabel.defaultTextFormat=skin.txLabel.getTextFormat();
         skin.txLabel.text="Matches";
         skin.addEventListener(Event.CLOSE,closeMenu);
         response=label(this,"SRP match menu",0,0,650,30,18);
         response.name="response"; response.visible=false;
         shield=new Sprite(); addChild(shield); shield.visible=false;
         addChild(panel); panel.visible=false;
         content=new Sprite(); panel.addChild(content);
         status=label(panel,"",32,621,590,66,18); status.wordWrap=true;
         retryButton=button(panel,"Retry",640,648,retry,"",120);
         retryButton.visible=false;
         addEventListener(Event.ENTER_FRAME,tick);
         addEventListener(Event.REMOVED_FROM_STAGE,removed);
         addEventListener(Event.ADDED_TO_STAGE,added);
      }
      private function layout(event:Event=null):void
      {
         if(!stage || !lobby.scaleX || !lobby.scaleY) return;
         var w:Number=stage.stageWidth/lobby.scaleX;
         var h:Number=stage.stageHeight/lobby.scaleY;
         panel.x=Math.round((w-810)/2); panel.y=Math.round((h-750)/2);
         shield.graphics.clear(); shield.graphics.beginFill(0,0.25);
         shield.graphics.drawRect(0,0,w,h); shield.graphics.endFill();
      }
      private function added(event:Event):void
      {
         if(event.target == this && stage)
         { stage.addEventListener(KeyboardEvent.KEY_DOWN,key); stage.addEventListener(Event.RESIZE,layout); layout(); }
      }
      private function removed(event:Event):void
      {
         if(event.target != this) return;
         if(stage) { stage.removeEventListener(KeyboardEvent.KEY_DOWN,key); stage.removeEventListener(Event.RESIZE,layout); }
         mainButton.removeEventListener(ButtonEvent.CLICK,openMenu);
         removeEventListener(Event.ENTER_FRAME,tick);
         results.dispose();
         ExternalInterface.call("srp_attach/closed-" + token);
      }
      private function key(event:KeyboardEvent):void
      {
         if(event.keyCode == 27 && panel.visible) { closeMenu(null); event.stopImmediatePropagation(); }
      }
      private function label(parent:Sprite,text:String,x:int,y:int,w:int,h:int,size:int):TextField
      {
         var field:TextField=new TextField();
         var format:TextFormat=new TextFormat(nativeTextStyle.font,size,nativeTextStyle.color,
            false,nativeTextStyle.italic);
         format.letterSpacing=nativeTextStyle.letterSpacing;
         field.embedFonts=nativeEmbeddedText; field.defaultTextFormat=format;
         field.x=x; field.y=y; field.width=w; field.height=h; field.text=text;
         field.mouseEnabled=false; field.selectable=false;
         parent.addChild(field); return field;
      }
      private function button(parent:Sprite,text:String,x:int,y:int,handler:Function,id:String="",w:int=170):Button
      {
         var control:Button=new SvButtonWide2();
         control.label=text; control.x=x; control.y=y; control.name=id;
         control.setSize(w,36); control.enabled=pending=="";
         control.addEventListener(ButtonEvent.CLICK,handler); parent.addChild(control);
         control.validateNow(); return control;
      }
      private function input(text:String,x:int,y:int,w:int,limit:int):TextField
      {
         var control:TextInputSkinnedChar=new TextInputSkinnedChar();
         control.x=x; control.y=y; control.setSize(w,36); control.text=text;
         content.addChild(control); control.validateNow();
         control.textField.maxChars=limit;
         return control.textField;
      }
      private function summary(title:String,count:String,noun:String,map:String,capacity:String):void
      {
         label(content,count,32,80,80,42,30);
         label(content,noun,32,124,84,28,16);
         label(content,title,128,72,640,38,22);
         summaryMap=label(content,map,128,121,178,28,18);
         label(content,capabilities && capabilities.mode_label ? String(capabilities.mode_label) : "Battery hunt",327,121,192,28,17);
         label(content,capacity,537,121,230,28,18);
      }
      private function divider(y:int):void
      {
         content.graphics.lineStyle(1,0x666666,0.55);
         content.graphics.moveTo(30,y); content.graphics.lineTo(778,y);
         content.graphics.lineStyle(1,0,0.8);
         content.graphics.moveTo(30,y+1); content.graphics.lineTo(778,y+1);
      }
      private function openMenu(event:Event):void
      {
         if(event) event.stopImmediatePropagation();
         if(!panel.visible) lobby.close_active_window();
         identityRetry=false; layout();
         shield.visible=true; panel.visible=true; render();
         if(!capabilities && pending=="") send("capabilities",{});
         else if(screen=="browser" && pending=="") send("list",{});
         else if(screen=="room" && room && pending=="") send("room",{match:room.id});
      }
      private function closeMenu(event:Event):void
      {
         // Keep draining a submitted mutation while hidden. Reopening retains
         // its room/result; hiding must not orphan a successful Create/Join.
         panel.visible=false;
         shield.visible=false;
         if(stage && stage.focus && contains(stage.focus)) stage.focus=null;
      }
      private function send(op:String,fields:Object,background:Boolean=false):void
      {
         if(pending!="") return;
         failedId="";
         backgroundRead=background; refreshAt=getTimer()+3000;
         operation=op; pending=String(++sequence);
         fields.v="1"; fields.id=token+"-"+pending; fields.op=op; fields.player=player;
         requestBody="";
         for(var field:String in fields)
            requestBody+=(requestBody=="" ? "" : "&")+encodeURIComponent(field)+"="+encodeURIComponent(String(fields[field]));
         deadline=getTimer()+10000;
         if(!backgroundRead) status.text="Loading…";
         // Retail installs the handler after constructing the movie.
         ExternalInterface.call("srp_attach/"+token);
         ExternalInterface.call("srp_request/"+token+"/"+pending+"/"+requestBody);
      }
      private function retry(event:Event):void
      {
         if(pending!="" || failedId=="") return;
         pending=failedId; failedId=""; deadline=getTimer()+10000;
         status.text="Retrying…";
         // Same request ID and body: a lost Create/Join response cannot
         // turn a retry into a second mutation.
         ExternalInterface.call("srp_request/"+token+"/"+pending+"/"+requestBody);
      }
      private function tick(event:Event):void
      {
         frames++;
         results.tick();
         // Native squad/localization updates may relabel or disable Play.
         // The SRP menu has its own authenticated admission checks.
         if(mainButton.label!="Matches") mainButton.label="Matches";
         if(!mainButton.enabled) mainButton.enabled=true;
         if(skin.txLabel.text!="Matches") skin.txLabel.text="Matches";
         retryButton.visible=failedId!="" && pending=="";
         for(var childIndex:int=0;childIndex<content.numChildren;childIndex++)
         {
            var action:Button=content.getChildAt(childIndex) as Button;
            if(action && action.enabled!=(pending=="")) action.enabled=pending=="";
         }
         if(frames==60) ExternalInterface.call("srp_probe");
         if(frames==61 && response.text.indexOf("SRP DLL connected:")==0)
            ExternalInterface.call("srp_probe_ack");
         if(pending!="") ExternalInterface.call("srp_poll/"+token);
         if(wireResponse!="")
         {
            var wire:String=wireResponse; wireResponse="";
            var first:int=wire.indexOf("\n");
            var second:int=wire.indexOf("\n",first+1);
            if(first<0 || second<0 || wire.substr(0,first)!=pending) return;
            var code:int=int(wire.substring(first+1,second));
            var body:String=wire.substr(second+1);
            if(code==401)
            {
               pending=""; failedId=""; requestBody=""; capabilities=null; room=null;
               rooms=[]; screen="browser"; render();
               // Returning from gameplay can invalidate the previous lobby job.
               // Retry only read-only capabilities, once per opening; never a mutation.
               if(panel.visible && !identityRetry)
               { identityRetry=true; send("capabilities",{},true); }
               else status.text=body;
               return;
            }
            if(code!=200)
            {
               // A background read may fail while the lobby reconnects.
               // Retry those reads on the normal interval; mutations retain
               // their request ID and still require an explicit Retry.
               failedId=backgroundRead ? "" : pending;
               pending=""; refreshAt=getTimer()+3000;
               status.text=body+(backgroundRead ? "" : " Use Retry to repeat the same request.");
               return;
            }
            pending="";
            try
            {
               var answer:Object=SrpJson.parse(body);
               if(!answer || answer.ok!==true)
               {
                  if(answer && answer.code=="room_unavailable")
                  { room=null; screen="browser"; render(); send("list",{},backgroundRead); return; }
                  status.text=answer ? String(answer.error) : "Invalid response"; return;
               }
               receive(answer.result);
            }
            catch(error:Error) { status.text="The menu service returned an invalid response."; }
         }
         if(pending!="" && getTimer()>deadline)
            status.text="The service is taking longer than expected. You can close this panel while it finishes.";
         // Read-only refresh follows native reconnects even when a persistent
         // service reuses the same account token. Never retry a mutation here.
         if(panel.visible && pending=="" && failedId=="" && getTimer()>=refreshAt)
         {
            refreshAt=getTimer()+3000;
            if(!capabilities) send("capabilities",{},true);
            else if(screen=="room" && room && (status.text=="" || backgroundRead || room.state!="waiting"))
               send("room",{match:room.id},true);
         }
      }
      private function receive(result:Object):void
      {
         status.text="";
         refreshAt=getTimer()+3000;
         if(operation=="capabilities")
         {
            if(result.version!=1 || !(result.maps is Array) || result.maps.length==0)
               throw new Error("Incompatible service");
            if(!(result.player is String) || result.player.length==0 || result.player.length>40)
               throw new Error("Missing session identity");
            player=result.player;
            capabilities=result; send("list",{},backgroundRead); return;
         }
         if(operation=="list") { rooms=result.rooms as Array; if(!rooms) throw new Error("Missing rooms"); screen="browser"; }
         else if(operation=="leave") { room=null; screen="browser"; send("list",{}); return; }
         else
         {
            var previousRoom:Object=room;
            if(!result.room || !(result.room.players is Array) || !(result.room.ready is Array))
               throw new Error("Missing room");
            room=result.room;
            screen="room";
            // Keep native controls and focus in place when a periodic read
            // reports no change; only a changed roster/state needs a redraw.
            if(backgroundRead && operation=="room" && previousRoom &&
               room.id==previousRoom.id && room.name==previousRoom.name &&
               room.map==previousRoom.map && room.capacity==previousRoom.capacity &&
               room.owner==previousRoom.owner && room.state==previousRoom.state &&
               room.players.join("\n")==previousRoom.players.join("\n") &&
               room.ready.join("\n")==previousRoom.ready.join("\n")) return;
         }
         render();
      }
      private function render():void
      {
         while(content.numChildren) content.removeChildAt(0);
         content.graphics.clear(); status.text="";
         if(screen=="browser")
         {
            summary("Available matches",String(rooms.length),rooms.length==1 ? "match" : "matches",
               capabilities ? String(capabilities.maps[0]) : "", "Up to 16 players");
            label(content,"Name",36,179,330,30,18);
            label(content,"Map",386,179,150,30,18);
            label(content,"Players",551,179,110,30,18);
            if(rooms.length==0)
            {
               label(content,"No matches available",36,250,700,32,20);
               label(content,"Create a match to invite other players.",36,287,700,30,18);
            }
            if(page*PAGE_SIZE>=rooms.length) page=0;
            for(var i:int=page*PAGE_SIZE;i<Math.min(rooms.length,page*PAGE_SIZE+PAGE_SIZE);i++)
            {
               var r:Object=rooms[i]; var y:int=235+(i-page*PAGE_SIZE)*44;
               label(content,String(r.name),36,y,335,32,19);
               label(content,String(r.map),386,y,150,32,19);
               label(content,r.players.length+" / "+r.capacity,551,y,100,32,19);
               if(r.state=="waiting" || (capabilities && capabilities.late_join &&
                  (r.players.length<r.capacity || r.players.indexOf(player)>=0)))
                  button(content,"Join",663,y-3,joinRoom,String(r.id),112);
               else label(content,"In progress",663,y,115,32,18);
               divider(y+38);
            }
            button(content,"Create match",24,707,createDialog,"",210);
            button(content,"Refresh",254,707,refresh,"",170);
            if(rooms.length>PAGE_SIZE) button(content,"Next page",630,577,nextPage,"",145);
         }
         else if(screen=="create")
         {
            summary("Create match","New","match",String(capabilities.maps[mapIndex]),"2–16 players");
            label(content,"Setting",36,179,190,30,18);
            label(content,"Value",250,179,500,30,18);
            label(content,"Name",36,254,190,30,19);
            nameInput=input("My match",250,250,500,48);
            label(content,"Map",36,317,190,30,19);
            button(content,String(capabilities.maps[mapIndex]),250,313,cycleMap,"",250);
            label(content,"Players",36,380,190,30,19);
            capacityInput=input("8",250,376,90,2); capacityInput.restrict="0-9";
            label(content,"2–16 players",360,382,280,30,18);
            label(content,"Mode",36,443,190,30,19);
            label(content,capabilities.mode_label ? String(capabilities.mode_label) : "Team deathmatch",250,443,500,30,19);
            button(content,"Create match",24,707,createRoom,"",210);
            button(content,"Back",254,707,back,"",170);
         }
         else if(screen=="room" && room)
         {
            summary(String(room.name),String(room.players.length),"players",String(room.map),room.players.length+" / "+room.capacity+" players");
            label(content,"Player",36,179,480,30,18);
            label(content,"Status",575,179,190,30,18);
            for(var slot:int=0;slot<room.players.length;slot++)
            {
               var member:String=String(room.players[slot]);
               label(content,member+(member==room.owner ? " (creator)" : ""),36,226+slot*23,520,28,18);
               label(content,room.ready.indexOf(member)>=0 ? "Ready" : "Not ready",575,226+slot*23,190,28,18);
            }
            button(content,"Refresh",24,707,refreshRoom,"",138);
            if(room.state=="waiting")
            {
               button(content,room.ready.indexOf(player)>=0 ? "Not ready" : "Ready",174,707,toggleReady,"",138);
               if(room.owner==player) button(content,"Start",324,707,startRoom,"",138);
               button(content,"Leave",474,707,leaveRoom,"",138);
            }
            else status.text="Match starting. Loading will open automatically.";
         }
         if(capabilities && capabilities.fixture && status.text=="")
            status.text="Local menu test service — gameplay is not connected yet.";
      }
      private function refresh(event:Event):void { send("list",{}); }
      private function refreshRoom(event:Event):void { send("room",{match:room.id}); }
      private function createDialog(event:Event):void
      {
         if(pending!="" || !capabilities) return; screen="create"; render();
         if(stage) stage.focus=nameInput;
      }
      private function cycleMap(event:Event):void
      {
         mapIndex=(mapIndex+1)%capabilities.maps.length;
         Button(event.currentTarget).label=String(capabilities.maps[mapIndex]);
         summaryMap.text=String(capabilities.maps[mapIndex]);
      }
      private function createRoom(event:Event):void
      {
         var count:int=int(capacityInput.text);
         if(nameInput.text.replace(/\s/g,"")=="" || count<2 || count>16)
         { status.text="Enter a room name and a capacity from 2 to 16."; return; }
         send("create",{name:nameInput.text,map:capabilities.maps[mapIndex],capacity:count});
      }
      private function joinRoom(event:Event):void { send("join",{match:event.currentTarget.name}); }
      private function toggleReady(event:Event):void { send("ready",{match:room.id,ready:room.ready.indexOf(player)>=0 ? "0" : "1"}); }
      private function startRoom(event:Event):void { send("start",{match:room.id}); }
      private function leaveRoom(event:Event):void { send("leave",{match:room.id}); }
      private function back(event:Event):void { if(pending=="") { screen="browser"; render(); } }
      private function nextPage(event:Event):void { page=(page+1)%Math.ceil(rooms.length/PAGE_SIZE); render(); }
   }
}
