// SPDX-License-Identifier: GPL-3.0-or-later
package
{
   // This retail GFx predates native AS3 JSON. Parse data without eval.
   public class SrpJson
   {
      private var text:String;
      private var pos:int = 0;
      public static function parse(text:String):Object
      {
         var parser:SrpJson = new SrpJson();
         if(text.length > 32768) throw new Error("Response too large");
         parser.text = text;
         var result:Object = parser.value(0);
         parser.space();
         if(parser.pos != text.length) throw new Error("Trailing JSON data");
         return result;
      }
      private function space():void
      {
         while(pos < text.length && " \r\n\t".indexOf(text.charAt(pos)) >= 0) pos++;
      }
      private function stringValue():String
      {
         pos++;
         var result:String = "";
         while(pos < text.length)
         {
            var c:String = text.charAt(pos++);
            if(c == '"') return result;
            if(c == "\\")
            {
               c = text.charAt(pos++);
               if(c == "u")
               {
                  var hex:String = text.substr(pos,4);
                  if(!/^[0-9a-fA-F]{4}$/.test(hex)) throw new Error("Invalid escape");
                  result += String.fromCharCode(parseInt(hex,16)); pos += 4;
               }
               else if(c == '"' || c == "\\" || c == "/") result += c;
               else if(c == "n") result += "\n";
               else if(c == "r") result += "\r";
               else if(c == "t") result += "\t";
               else if(c == "b") result += "\b";
               else if(c == "f") result += "\f";
               else throw new Error("Invalid escape");
            }
            else
            {
               if(c.charCodeAt(0) < 32) throw new Error("Control in string");
               result += c;
            }
         }
         throw new Error("Unterminated string");
      }
      private function value(depth:int):Object
      {
         if(depth > 20) throw new Error("JSON too deep");
         space();
         var c:String = text.charAt(pos);
         if(c == '"') return stringValue();
         if(c == "{" || c == "[")
         {
            var array:Boolean = c == "[";
            var end:String = array ? "]" : "}";
            var output:Object = array ? [] : {};
            pos++; space();
            if(text.charAt(pos) == end) { pos++; return output; }
            while(pos < text.length)
            {
               var key:String = "";
               if(!array)
               {
                  space();
                  if(text.charAt(pos) != '"') throw new Error("Expected object key");
                  key = stringValue(); space();
                  if(key == "__proto__" || key == "constructor" || key == "prototype")
                     throw new Error("Unsupported object key");
                  if(text.charAt(pos++) != ":") throw new Error("Expected colon");
               }
               var child:Object = value(depth + 1);
               if(array) output.push(child); else output[key] = child;
               space(); c = text.charAt(pos++);
               if(c == end) return output;
               if(c != ",") throw new Error("Expected comma");
            }
            throw new Error("Unterminated container");
         }
         if(text.substr(pos,4) == "true") { pos += 4; return true; }
         if(text.substr(pos,5) == "false") { pos += 5; return false; }
         if(text.substr(pos,4) == "null") { pos += 4; return null; }
         var match:Array = /^-?(0|[1-9][0-9]*)(\.[0-9]+)?([eE][+-]?[0-9]+)?/.exec(text.substr(pos));
         if(match == null) throw new Error("Expected JSON value");
         pos += String(match[0]).length;
         return Number(match[0]);
      }
   }
}
