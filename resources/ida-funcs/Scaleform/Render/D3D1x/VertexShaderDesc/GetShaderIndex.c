Scaleform::Render::D3D1x::VertexShaderDesc::ShaderIndex __usercall Scaleform::Render::D3D1x::VertexShaderDesc::GetShaderIndex@<eax>(
        int shader@<eax>,
        Scaleform::Render::D3D1x::ShaderDesc::ShaderVersion ver@<ecx>)
{
  int v2; // ecx
  Scaleform::Render::D3D1x::VertexShaderDesc::ShaderIndex result; // eax
  int v4; // eax
  bool v5; // zf
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax

  if ( ver == ShaderVersion_D3D1xFL91 )
  {
    if ( shader <= 4096 )
    {
      if ( shader == 4096 )
        return 49;
      switch ( shader )
      {
        case 1:
        case 2:
          return 1;
        case 3:
        case 4:
          goto $LN1229_0;
        case 9:
        case 10:
          goto $LN1561;
        case 11:
        case 12:
          goto $LN1559;
        case 17:
        case 18:
        case 65:
        case 66:
          goto $LN1555_0;
        case 19:
        case 20:
        case 67:
        case 68:
          goto $LN1553_0;
        case 25:
        case 26:
        case 73:
        case 74:
          goto $LN1549;
        case 27:
        case 28:
        case 75:
        case 76:
          goto $LN1547;
        case 33:
        case 34:
          return 2;
        case 35:
        case 36:
          goto $LN1541_0;
        case 41:
        case 42:
          goto $LN1537;
        case 43:
        case 44:
          goto $LN1535;
        case 49:
        case 50:
        case 97:
        case 98:
          goto $LN1531_0;
        case 51:
        case 52:
        case 99:
        case 100:
          goto $LN1529_0;
        case 57:
        case 58:
        case 105:
        case 106:
          goto $LN1525;
        case 59:
        case 60:
        case 107:
        case 108:
          goto $LN1523;
        case 129:
        case 130:
          result = VSI_D3D1xFL91_VVertex;
          break;
        case 131:
        case 132:
          result = VSI_D3D1xFL91_VBatchVertex;
          break;
        case 137:
        case 138:
          result = VSI_D3D1xFL91_VPosition3dVertex;
          break;
        case 139:
        case 140:
          result = VSI_D3D1xFL91_VBatchPosition3dVertex;
          break;
        case 145:
        case 146:
        case 193:
        case 194:
          result = VSI_D3D1xFL91_VVertexCxform;
          break;
        case 147:
        case 148:
        case 195:
        case 196:
          result = VSI_D3D1xFL91_VBatchVertexCxform;
          break;
        case 153:
        case 154:
        case 201:
        case 202:
          result = VSI_D3D1xFL91_VPosition3dVertexCxform;
          break;
        case 155:
        case 156:
        case 203:
        case 204:
          result = VSI_D3D1xFL91_VBatchPosition3dVertexCxform;
          break;
        case 161:
        case 162:
          result = VSI_D3D1xFL91_VVertexEAlpha;
          break;
        case 163:
        case 164:
          result = VSI_D3D1xFL91_VBatchVertexEAlpha;
          break;
        case 169:
        case 170:
          result = VSI_D3D1xFL91_VPosition3dVertexEAlpha;
          break;
        case 171:
        case 172:
          result = VSI_D3D1xFL91_VBatchPosition3dVertexEAlpha;
          break;
        case 177:
        case 178:
        case 225:
        case 226:
          result = VSI_D3D1xFL91_VVertexCxformEAlpha;
          break;
        case 179:
        case 180:
        case 227:
        case 228:
          result = VSI_D3D1xFL91_VBatchVertexCxformEAlpha;
          break;
        case 185:
        case 186:
        case 233:
        case 234:
          result = VSI_D3D1xFL91_VPosition3dVertexCxformEAlpha;
          break;
        case 187:
        case 188:
        case 235:
        case 236:
          result = VSI_D3D1xFL91_VBatchPosition3dVertexCxformEAlpha;
          break;
        case 257:
        case 258:
        case 289:
        case 290:
          result = VSI_D3D1xFL91_VTexTGTexTG;
          break;
        case 259:
        case 260:
        case 291:
        case 292:
          result = VSI_D3D1xFL91_VBatchTexTGTexTG;
          break;
        case 265:
        case 266:
        case 297:
        case 298:
          result = VSI_D3D1xFL91_VPosition3dTexTGTexTG;
          break;
        case 267:
        case 268:
        case 299:
        case 300:
          result = VSI_D3D1xFL91_VBatchPosition3dTexTGTexTG;
          break;
        case 273:
        case 274:
        case 305:
        case 306:
        case 321:
        case 322:
        case 353:
        case 354:
          result = VSI_D3D1xFL91_VTexTGTexTGCxform;
          break;
        case 275:
        case 276:
        case 307:
        case 308:
        case 323:
        case 324:
        case 355:
        case 356:
          result = VSI_D3D1xFL91_VBatchTexTGTexTGCxform;
          break;
        case 281:
        case 282:
        case 313:
        case 314:
        case 329:
        case 330:
        case 361:
        case 362:
          result = VSI_D3D1xFL91_VPosition3dTexTGTexTGCxform;
          break;
        case 283:
        case 284:
        case 315:
        case 316:
        case 331:
        case 332:
        case 363:
        case 364:
          result = VSI_D3D1xFL91_VBatchPosition3dTexTGTexTGCxform;
          break;
        case 513:
        case 514:
        case 545:
        case 546:
          result = VSI_D3D1xFL91_VTexTGVertex;
          break;
        case 515:
        case 516:
        case 547:
        case 548:
          result = VSI_D3D1xFL91_VBatchTexTGVertex;
          break;
        case 521:
        case 522:
        case 553:
        case 554:
          result = VSI_D3D1xFL91_VPosition3dTexTGVertex;
          break;
        case 523:
        case 524:
        case 555:
        case 556:
          result = VSI_D3D1xFL91_VBatchPosition3dTexTGVertex;
          break;
        case 529:
        case 530:
        case 561:
        case 562:
        case 577:
        case 578:
        case 609:
        case 610:
          result = VSI_D3D1xFL91_VTexTGVertexCxform;
          break;
        case 531:
        case 532:
        case 563:
        case 564:
        case 579:
        case 580:
        case 611:
        case 612:
          result = VSI_D3D1xFL91_VBatchTexTGVertexCxform;
          break;
        case 537:
        case 538:
        case 569:
        case 570:
        case 585:
        case 586:
        case 617:
        case 618:
          result = VSI_D3D1xFL91_VPosition3dTexTGVertexCxform;
          break;
        case 539:
        case 540:
        case 571:
        case 572:
        case 587:
        case 588:
        case 619:
        case 620:
          result = VSI_D3D1xFL91_VBatchPosition3dTexTGVertexCxform;
          break;
        default:
          return 0;
      }
      return result;
    }
    if ( shader <= 5120 )
    {
      if ( shader == 5120 )
        return 50;
      switch ( shader )
      {
        case 4097:
          return 49;
        case 4098:
        case 4099:
          result = VSI_D3D1xFL91_VBatchSolid;
          break;
        case 4104:
        case 4105:
          result = VSI_D3D1xFL91_VPosition3dSolid;
          break;
        case 4106:
        case 4107:
          result = VSI_D3D1xFL91_VBatchPosition3dSolid;
          break;
        default:
          return 0;
      }
      return result;
    }
    if ( shader <= 6144 )
    {
      if ( shader == 6144 )
        return 51;
      switch ( shader )
      {
        case 5121:
          return 50;
        case 5122:
        case 5123:
          result = VSI_D3D1xFL91_VBatchText;
          break;
        case 5128:
        case 5129:
          result = VSI_D3D1xFL91_VPosition3dText;
          break;
        case 5130:
        case 5131:
          result = VSI_D3D1xFL91_VBatchPosition3dText;
          break;
        default:
          return 0;
      }
      return result;
    }
    if ( shader > 0x2000 )
    {
      if ( shader <= 10240 )
      {
        if ( shader != 10240 )
        {
          switch ( shader )
          {
            case 8193:
              return 1;
            case 8194:
            case 8195:
              goto $LN1229_0;
            case 8200:
            case 8201:
              goto $LN1561;
            case 8202:
            case 8203:
              goto $LN1559;
            case 8208:
            case 8209:
            case 8256:
            case 8257:
              goto $LN1555_0;
            case 8210:
            case 8211:
            case 8258:
            case 8259:
              goto $LN1553_0;
            case 8216:
            case 8217:
            case 8264:
            case 8265:
              goto $LN1549;
            case 8218:
            case 8219:
            case 8266:
            case 8267:
              goto $LN1547;
            case 8224:
            case 8225:
              return 2;
            case 8226:
            case 8227:
              goto $LN1541_0;
            case 8232:
            case 8233:
              goto $LN1537;
            case 8234:
            case 8235:
              goto $LN1535;
            case 8240:
            case 8241:
            case 8288:
            case 8289:
              goto $LN1531_0;
            case 8242:
            case 8243:
            case 8290:
            case 8291:
              goto $LN1529_0;
            case 8248:
            case 8249:
            case 8296:
            case 8297:
              goto $LN1525;
            case 8250:
            case 8251:
            case 8298:
            case 8299:
              goto $LN1523;
            default:
              return 0;
          }
        }
        return 1;
      }
      if ( shader > 12288 )
      {
        if ( shader <= 21520 )
        {
          if ( shader == 21520 )
            return 0;
          if ( shader > 20481 )
          {
            if ( shader <= 20992 )
              return 0;
            goto LABEL_242;
          }
          if ( shader > 12321 )
            return 0;
          if ( shader != 12321 )
          {
            v12 = shader - 12289;
            if ( !v12 )
              return 1;
            if ( v12 != 31 )
              return 0;
          }
          return 2;
        }
        if ( shader > 24576 )
        {
          if ( shader > 28672 )
          {
            if ( shader != 0x8000 )
              return shader == 36864;
          }
          else if ( shader != 28672 )
          {
            switch ( shader )
            {
              case 24577:
              case 24578:
                return 65;
              case 24580:
              case 24581:
              case 24582:
                result = VSI_D3D1xFL91_VDrawableCopyPixelsAlpha;
                break;
              default:
                return 0;
            }
            return result;
          }
        }
        else if ( shader != 24576 )
        {
          return 0;
        }
        return 65;
      }
      if ( shader != 12288 )
      {
        switch ( shader )
        {
          case 10241:
            return 1;
          case 10242:
          case 10243:
$LN1229_0:
            result = VSI_D3D1xFL91_VBatchTexTG;
            break;
          case 10248:
          case 10249:
$LN1561:
            result = VSI_D3D1xFL91_VPosition3dTexTG;
            break;
          case 10250:
          case 10251:
$LN1559:
            result = VSI_D3D1xFL91_VBatchPosition3dTexTG;
            break;
          case 10256:
          case 10257:
          case 10304:
          case 10305:
$LN1555_0:
            result = VSI_D3D1xFL91_VTexTGCxform;
            break;
          case 10258:
          case 10259:
          case 10306:
          case 10307:
$LN1553_0:
            result = VSI_D3D1xFL91_VBatchTexTGCxform;
            break;
          case 10264:
          case 10265:
          case 10312:
          case 10313:
$LN1549:
            result = VSI_D3D1xFL91_VPosition3dTexTGCxform;
            break;
          case 10266:
          case 10267:
          case 10314:
          case 10315:
$LN1547:
            result = VSI_D3D1xFL91_VBatchPosition3dTexTGCxform;
            break;
          case 10272:
          case 10273:
            return 2;
          case 10274:
          case 10275:
$LN1541_0:
            result = VSI_D3D1xFL91_VBatchTexTGEAlpha;
            break;
          case 10280:
          case 10281:
$LN1537:
            result = VSI_D3D1xFL91_VPosition3dTexTGEAlpha;
            break;
          case 10282:
          case 10283:
$LN1535:
            result = VSI_D3D1xFL91_VBatchPosition3dTexTGEAlpha;
            break;
          case 10288:
          case 10289:
          case 10336:
          case 10337:
$LN1531_0:
            result = VSI_D3D1xFL91_VTexTGCxformEAlpha;
            break;
          case 10290:
          case 10291:
          case 10338:
          case 10339:
$LN1529_0:
            result = VSI_D3D1xFL91_VBatchTexTGCxformEAlpha;
            break;
          case 10296:
          case 10297:
          case 10344:
          case 10345:
$LN1525:
            result = VSI_D3D1xFL91_VPosition3dTexTGCxformEAlpha;
            break;
          case 10298:
          case 10299:
          case 10346:
          case 10347:
$LN1523:
            result = VSI_D3D1xFL91_VBatchPosition3dTexTGCxformEAlpha;
            break;
          default:
            return 0;
        }
        return result;
      }
    }
    else if ( shader != 0x2000 )
    {
      switch ( shader )
      {
        case 6145:
          return 51;
        case 6146:
        case 6147:
          result = VSI_D3D1xFL91_VBatchTextColor;
          break;
        case 6152:
        case 6153:
          result = VSI_D3D1xFL91_VPosition3dTextColor;
          break;
        case 6154:
        case 6155:
          result = VSI_D3D1xFL91_VBatchPosition3dTextColor;
          break;
        case 6160:
        case 6161:
          result = VSI_D3D1xFL91_VTextColorCxform;
          break;
        case 6162:
        case 6163:
          result = VSI_D3D1xFL91_VBatchTextColorCxform;
          break;
        case 6168:
        case 6169:
          result = VSI_D3D1xFL91_VPosition3dTextColorCxform;
          break;
        case 6170:
        case 6171:
          result = VSI_D3D1xFL91_VBatchPosition3dTextColorCxform;
          break;
        default:
          return 0;
      }
      return result;
    }
    return 1;
  }
  v2 = ver - 1;
  if ( !v2 )
  {
    if ( shader <= 4096 )
    {
      if ( shader == 4096 )
        return 115;
      switch ( shader )
      {
        case 1:
        case 2:
          return 67;
        case 3:
        case 4:
          goto $LN706_0;
        case 9:
        case 10:
          goto $LN1038;
        case 11:
        case 12:
          goto $LN1036;
        case 17:
        case 18:
        case 65:
        case 66:
          goto $LN1032_0;
        case 19:
        case 20:
        case 67:
        case 68:
          goto $LN1030_0;
        case 25:
        case 26:
        case 73:
        case 74:
          goto $LN1026;
        case 27:
        case 28:
        case 75:
        case 76:
          goto $LN1024;
        case 33:
        case 34:
          return 68;
        case 35:
        case 36:
          goto $LN1018_0;
        case 41:
        case 42:
          goto $LN1014;
        case 43:
        case 44:
          goto $LN1012;
        case 49:
        case 50:
        case 97:
        case 98:
          goto $LN1008_0;
        case 51:
        case 52:
        case 99:
        case 100:
          goto $LN1006_0;
        case 57:
        case 58:
        case 105:
        case 106:
          goto $LN1002;
        case 59:
        case 60:
        case 107:
        case 108:
          goto $LN1000;
        case 129:
        case 130:
          result = VSI_D3D1xFL93_VVertex;
          break;
        case 131:
        case 132:
          result = VSI_D3D1xFL93_VBatchVertex;
          break;
        case 137:
        case 138:
          result = VSI_D3D1xFL93_VPosition3dVertex;
          break;
        case 139:
        case 140:
          result = VSI_D3D1xFL93_VBatchPosition3dVertex;
          break;
        case 145:
        case 146:
        case 193:
        case 194:
          result = VSI_D3D1xFL93_VVertexCxform;
          break;
        case 147:
        case 148:
        case 195:
        case 196:
          result = VSI_D3D1xFL93_VBatchVertexCxform;
          break;
        case 153:
        case 154:
        case 201:
        case 202:
          result = VSI_D3D1xFL93_VPosition3dVertexCxform;
          break;
        case 155:
        case 156:
        case 203:
        case 204:
          result = VSI_D3D1xFL93_VBatchPosition3dVertexCxform;
          break;
        case 161:
        case 162:
          result = VSI_D3D1xFL93_VVertexEAlpha;
          break;
        case 163:
        case 164:
          result = VSI_D3D1xFL93_VBatchVertexEAlpha;
          break;
        case 169:
        case 170:
          result = VSI_D3D1xFL93_VPosition3dVertexEAlpha;
          break;
        case 171:
        case 172:
          result = VSI_D3D1xFL93_VBatchPosition3dVertexEAlpha;
          break;
        case 177:
        case 178:
        case 225:
        case 226:
          result = VSI_D3D1xFL93_VVertexCxformEAlpha;
          break;
        case 179:
        case 180:
        case 227:
        case 228:
          result = VSI_D3D1xFL93_VBatchVertexCxformEAlpha;
          break;
        case 185:
        case 186:
        case 233:
        case 234:
          result = VSI_D3D1xFL93_VPosition3dVertexCxformEAlpha;
          break;
        case 187:
        case 188:
        case 235:
        case 236:
          result = VSI_D3D1xFL93_VBatchPosition3dVertexCxformEAlpha;
          break;
        case 257:
        case 258:
        case 289:
        case 290:
          result = VSI_D3D1xFL93_VTexTGTexTG;
          break;
        case 259:
        case 260:
        case 291:
        case 292:
          result = VSI_D3D1xFL93_VBatchTexTGTexTG;
          break;
        case 265:
        case 266:
        case 297:
        case 298:
          result = VSI_D3D1xFL93_VPosition3dTexTGTexTG;
          break;
        case 267:
        case 268:
        case 299:
        case 300:
          result = VSI_D3D1xFL93_VBatchPosition3dTexTGTexTG;
          break;
        case 273:
        case 274:
        case 305:
        case 306:
        case 321:
        case 322:
        case 353:
        case 354:
          result = VSI_D3D1xFL93_VTexTGTexTGCxform;
          break;
        case 275:
        case 276:
        case 307:
        case 308:
        case 323:
        case 324:
        case 355:
        case 356:
          result = VSI_D3D1xFL93_VBatchTexTGTexTGCxform;
          break;
        case 281:
        case 282:
        case 313:
        case 314:
        case 329:
        case 330:
        case 361:
        case 362:
          result = VSI_D3D1xFL93_VPosition3dTexTGTexTGCxform;
          break;
        case 283:
        case 284:
        case 315:
        case 316:
        case 331:
        case 332:
        case 363:
        case 364:
          result = VSI_D3D1xFL93_VBatchPosition3dTexTGTexTGCxform;
          break;
        case 513:
        case 514:
        case 545:
        case 546:
          result = VSI_D3D1xFL93_VTexTGVertex;
          break;
        case 515:
        case 516:
        case 547:
        case 548:
          result = VSI_D3D1xFL93_VBatchTexTGVertex;
          break;
        case 521:
        case 522:
        case 553:
        case 554:
          result = VSI_D3D1xFL93_VPosition3dTexTGVertex;
          break;
        case 523:
        case 524:
        case 555:
        case 556:
          result = VSI_D3D1xFL93_VBatchPosition3dTexTGVertex;
          break;
        case 529:
        case 530:
        case 561:
        case 562:
        case 577:
        case 578:
        case 609:
        case 610:
          result = VSI_D3D1xFL93_VTexTGVertexCxform;
          break;
        case 531:
        case 532:
        case 563:
        case 564:
        case 579:
        case 580:
        case 611:
        case 612:
          result = VSI_D3D1xFL93_VBatchTexTGVertexCxform;
          break;
        case 537:
        case 538:
        case 569:
        case 570:
        case 585:
        case 586:
        case 617:
        case 618:
          result = VSI_D3D1xFL93_VPosition3dTexTGVertexCxform;
          break;
        case 539:
        case 540:
        case 571:
        case 572:
        case 587:
        case 588:
        case 619:
        case 620:
          result = VSI_D3D1xFL93_VBatchPosition3dTexTGVertexCxform;
          break;
        default:
          return 0;
      }
      return result;
    }
    if ( shader <= 5120 )
    {
      if ( shader == 5120 )
        return 116;
      switch ( shader )
      {
        case 4097:
          return 115;
        case 4098:
        case 4099:
          result = VSI_D3D1xFL93_VBatchSolid;
          break;
        case 4104:
        case 4105:
          result = VSI_D3D1xFL93_VPosition3dSolid;
          break;
        case 4106:
        case 4107:
          result = VSI_D3D1xFL93_VBatchPosition3dSolid;
          break;
        default:
          return 0;
      }
      return result;
    }
    if ( shader <= 6144 )
    {
      if ( shader == 6144 )
        return 117;
      switch ( shader )
      {
        case 5121:
          return 116;
        case 5122:
        case 5123:
          result = VSI_D3D1xFL93_VBatchText;
          break;
        case 5128:
        case 5129:
          result = VSI_D3D1xFL93_VPosition3dText;
          break;
        case 5130:
        case 5131:
          result = VSI_D3D1xFL93_VBatchPosition3dText;
          break;
        default:
          return 0;
      }
      return result;
    }
    if ( shader <= 0x2000 )
    {
      if ( shader != 0x2000 )
      {
        switch ( shader )
        {
          case 6145:
            return 117;
          case 6146:
          case 6147:
            result = VSI_D3D1xFL93_VBatchTextColor;
            break;
          case 6152:
          case 6153:
            result = VSI_D3D1xFL93_VPosition3dTextColor;
            break;
          case 6154:
          case 6155:
            result = VSI_D3D1xFL93_VBatchPosition3dTextColor;
            break;
          case 6160:
          case 6161:
            result = VSI_D3D1xFL93_VTextColorCxform;
            break;
          case 6162:
          case 6163:
            result = VSI_D3D1xFL93_VBatchTextColorCxform;
            break;
          case 6168:
          case 6169:
            result = VSI_D3D1xFL93_VPosition3dTextColorCxform;
            break;
          case 6170:
          case 6171:
            result = VSI_D3D1xFL93_VBatchPosition3dTextColorCxform;
            break;
          default:
            return 0;
        }
        return result;
      }
      return 67;
    }
    if ( shader <= 10240 )
    {
      if ( shader != 10240 )
      {
        switch ( shader )
        {
          case 8193:
            return 67;
          case 8194:
          case 8195:
            goto $LN706_0;
          case 8200:
          case 8201:
            goto $LN1038;
          case 8202:
          case 8203:
            goto $LN1036;
          case 8208:
          case 8209:
          case 8256:
          case 8257:
            goto $LN1032_0;
          case 8210:
          case 8211:
          case 8258:
          case 8259:
            goto $LN1030_0;
          case 8216:
          case 8217:
          case 8264:
          case 8265:
            goto $LN1026;
          case 8218:
          case 8219:
          case 8266:
          case 8267:
            goto $LN1024;
          case 8224:
          case 8225:
            return 68;
          case 8226:
          case 8227:
            goto $LN1018_0;
          case 8232:
          case 8233:
            goto $LN1014;
          case 8234:
          case 8235:
            goto $LN1012;
          case 8240:
          case 8241:
          case 8288:
          case 8289:
            goto $LN1008_0;
          case 8242:
          case 8243:
          case 8290:
          case 8291:
            goto $LN1006_0;
          case 8248:
          case 8249:
          case 8296:
          case 8297:
            goto $LN1002;
          case 8250:
          case 8251:
          case 8298:
          case 8299:
            goto $LN1000;
          default:
            return 0;
        }
      }
      return 67;
    }
    if ( shader <= 12288 )
    {
      if ( shader != 12288 )
      {
        switch ( shader )
        {
          case 10241:
            return 67;
          case 10242:
          case 10243:
$LN706_0:
            result = VSI_D3D1xFL93_VBatchTexTG;
            break;
          case 10248:
          case 10249:
$LN1038:
            result = VSI_D3D1xFL93_VPosition3dTexTG;
            break;
          case 10250:
          case 10251:
$LN1036:
            result = VSI_D3D1xFL93_VBatchPosition3dTexTG;
            break;
          case 10256:
          case 10257:
          case 10304:
          case 10305:
$LN1032_0:
            result = VSI_D3D1xFL93_VTexTGCxform;
            break;
          case 10258:
          case 10259:
          case 10306:
          case 10307:
$LN1030_0:
            result = VSI_D3D1xFL93_VBatchTexTGCxform;
            break;
          case 10264:
          case 10265:
          case 10312:
          case 10313:
$LN1026:
            result = VSI_D3D1xFL93_VPosition3dTexTGCxform;
            break;
          case 10266:
          case 10267:
          case 10314:
          case 10315:
$LN1024:
            result = VSI_D3D1xFL93_VBatchPosition3dTexTGCxform;
            break;
          case 10272:
          case 10273:
            return 68;
          case 10274:
          case 10275:
$LN1018_0:
            result = VSI_D3D1xFL93_VBatchTexTGEAlpha;
            break;
          case 10280:
          case 10281:
$LN1014:
            result = VSI_D3D1xFL93_VPosition3dTexTGEAlpha;
            break;
          case 10282:
          case 10283:
$LN1012:
            result = VSI_D3D1xFL93_VBatchPosition3dTexTGEAlpha;
            break;
          case 10288:
          case 10289:
          case 10336:
          case 10337:
$LN1008_0:
            result = VSI_D3D1xFL93_VTexTGCxformEAlpha;
            break;
          case 10290:
          case 10291:
          case 10338:
          case 10339:
$LN1006_0:
            result = VSI_D3D1xFL93_VBatchTexTGCxformEAlpha;
            break;
          case 10296:
          case 10297:
          case 10344:
          case 10345:
$LN1002:
            result = VSI_D3D1xFL93_VPosition3dTexTGCxformEAlpha;
            break;
          case 10298:
          case 10299:
          case 10346:
          case 10347:
$LN1000:
            result = VSI_D3D1xFL93_VBatchPosition3dTexTGCxformEAlpha;
            break;
          default:
            return 0;
        }
        return result;
      }
      return 67;
    }
    if ( shader > 21520 )
    {
      if ( shader > 24576 )
      {
        if ( shader > 28672 )
        {
          if ( shader != 0x8000 )
          {
            if ( shader != 36864 )
              return 0;
            return 67;
          }
        }
        else if ( shader != 28672 )
        {
          switch ( shader )
          {
            case 24577:
            case 24578:
              return 131;
            case 24580:
            case 24581:
            case 24582:
              result = VSI_D3D1xFL93_VDrawableCopyPixelsAlpha;
              break;
            default:
              return 0;
          }
          return result;
        }
      }
      else if ( shader != 24576 )
      {
        return 0;
      }
      return 131;
    }
    if ( shader == 21520 )
      return 0;
    if ( shader <= 20481 )
    {
      if ( shader > 12321 )
        return 0;
      if ( shader != 12321 )
      {
        v10 = shader - 12289;
        if ( !v10 )
          return 67;
        if ( v10 != 31 )
          return 0;
      }
      return 68;
    }
    if ( shader <= 20992 )
      return 0;
LABEL_242:
    v11 = shader - 20993;
    if ( v11 && v11 != 7 )
      return 0;
    return 0;
  }
  if ( v2 != 1 )
    return 0;
  if ( shader <= 4096 )
  {
    if ( shader == 4096 )
      return 205;
    switch ( shader )
    {
      case 1:
      case 2:
        return 133;
      case 3:
      case 4:
        goto $LN183_0;
      case 5:
      case 6:
        goto $LN517_0;
      case 9:
      case 10:
        goto $LN515;
      case 11:
      case 12:
        goto $LN513;
      case 13:
      case 14:
        goto $LN511;
      case 17:
      case 18:
      case 65:
      case 66:
        goto $LN509_0;
      case 19:
      case 20:
      case 67:
      case 68:
        goto $LN507_0;
      case 21:
      case 22:
      case 69:
      case 70:
        goto $LN505_0;
      case 25:
      case 26:
      case 73:
      case 74:
        goto $LN503;
      case 27:
      case 28:
      case 75:
      case 76:
        goto $LN501;
      case 29:
      case 30:
      case 77:
      case 78:
        goto $LN499;
      case 33:
      case 34:
        return 134;
      case 35:
      case 36:
        goto $LN495_0;
      case 37:
      case 38:
        goto $LN493_0;
      case 41:
      case 42:
        goto $LN491;
      case 43:
      case 44:
        goto $LN489;
      case 45:
      case 46:
        goto $LN487;
      case 49:
      case 50:
      case 97:
      case 98:
        goto $LN485_0;
      case 51:
      case 52:
      case 99:
      case 100:
        goto $LN483_1;
      case 53:
      case 54:
      case 101:
      case 102:
        goto $LN481_0;
      case 57:
      case 58:
      case 105:
      case 106:
        goto $LN479;
      case 59:
      case 60:
      case 107:
      case 108:
        goto $LN477;
      case 61:
      case 62:
      case 109:
      case 110:
        goto $LN475;
      case 129:
      case 130:
        result = VSI_D3D1xFL1x_VVertex;
        break;
      case 131:
      case 132:
        result = VSI_D3D1xFL1x_VBatchVertex;
        break;
      case 133:
      case 134:
        result = VSI_D3D1xFL1x_VInstancedVertex;
        break;
      case 137:
      case 138:
        result = VSI_D3D1xFL1x_VPosition3dVertex;
        break;
      case 139:
      case 140:
        result = VSI_D3D1xFL1x_VBatchPosition3dVertex;
        break;
      case 141:
      case 142:
        result = VSI_D3D1xFL1x_VInstancedPosition3dVertex;
        break;
      case 145:
      case 146:
      case 193:
      case 194:
        result = VSI_D3D1xFL1x_VVertexCxform;
        break;
      case 147:
      case 148:
      case 195:
      case 196:
        result = VSI_D3D1xFL1x_VBatchVertexCxform;
        break;
      case 149:
      case 150:
      case 197:
      case 198:
        result = VSI_D3D1xFL1x_VInstancedVertexCxform;
        break;
      case 153:
      case 154:
      case 201:
      case 202:
        result = VSI_D3D1xFL1x_VPosition3dVertexCxform;
        break;
      case 155:
      case 156:
      case 203:
      case 204:
        result = VSI_D3D1xFL1x_VBatchPosition3dVertexCxform;
        break;
      case 157:
      case 158:
      case 205:
      case 206:
        result = VSI_D3D1xFL1x_VInstancedPosition3dVertexCxform;
        break;
      case 161:
      case 162:
        result = VSI_D3D1xFL1x_VVertexEAlpha;
        break;
      case 163:
      case 164:
        result = VSI_D3D1xFL1x_VBatchVertexEAlpha;
        break;
      case 165:
      case 166:
        result = VSI_D3D1xFL1x_VInstancedVertexEAlpha;
        break;
      case 169:
      case 170:
        result = VSI_D3D1xFL1x_VPosition3dVertexEAlpha;
        break;
      case 171:
      case 172:
        result = VSI_D3D1xFL1x_VBatchPosition3dVertexEAlpha;
        break;
      case 173:
      case 174:
        result = VSI_D3D1xFL1x_VInstancedPosition3dVertexEAlpha;
        break;
      case 177:
      case 178:
      case 225:
      case 226:
        result = VSI_D3D1xFL1x_VVertexCxformEAlpha;
        break;
      case 179:
      case 180:
      case 227:
      case 228:
        result = VSI_D3D1xFL1x_VBatchVertexCxformEAlpha;
        break;
      case 181:
      case 182:
      case 229:
      case 230:
        result = VSI_D3D1xFL1x_VInstancedVertexCxformEAlpha;
        break;
      case 185:
      case 186:
      case 233:
      case 234:
        result = VSI_D3D1xFL1x_VPosition3dVertexCxformEAlpha;
        break;
      case 187:
      case 188:
      case 235:
      case 236:
        result = VSI_D3D1xFL1x_VBatchPosition3dVertexCxformEAlpha;
        break;
      case 189:
      case 190:
      case 237:
      case 238:
        result = VSI_D3D1xFL1x_VInstancedPosition3dVertexCxformEAlpha;
        break;
      case 257:
      case 258:
      case 289:
      case 290:
        result = VSI_D3D1xFL1x_VTexTGTexTG;
        break;
      case 259:
      case 260:
      case 291:
      case 292:
        result = VSI_D3D1xFL1x_VBatchTexTGTexTG;
        break;
      case 261:
      case 262:
      case 293:
      case 294:
        result = VSI_D3D1xFL1x_VInstancedTexTGTexTG;
        break;
      case 265:
      case 266:
      case 297:
      case 298:
        result = VSI_D3D1xFL1x_VPosition3dTexTGTexTG;
        break;
      case 267:
      case 268:
      case 299:
      case 300:
        result = VSI_D3D1xFL1x_VBatchPosition3dTexTGTexTG;
        break;
      case 269:
      case 270:
      case 301:
      case 302:
        result = VSI_D3D1xFL1x_VInstancedPosition3dTexTGTexTG;
        break;
      case 273:
      case 274:
      case 305:
      case 306:
      case 321:
      case 322:
      case 353:
      case 354:
        result = VSI_D3D1xFL1x_VTexTGTexTGCxform;
        break;
      case 275:
      case 276:
      case 307:
      case 308:
      case 323:
      case 324:
      case 355:
      case 356:
        result = VSI_D3D1xFL1x_VBatchTexTGTexTGCxform;
        break;
      case 277:
      case 278:
      case 309:
      case 310:
      case 325:
      case 326:
      case 357:
      case 358:
        result = VSI_D3D1xFL1x_VInstancedTexTGTexTGCxform;
        break;
      case 281:
      case 282:
      case 313:
      case 314:
      case 329:
      case 330:
      case 361:
      case 362:
        result = VSI_D3D1xFL1x_VPosition3dTexTGTexTGCxform;
        break;
      case 283:
      case 284:
      case 315:
      case 316:
      case 331:
      case 332:
      case 363:
      case 364:
        result = VSI_D3D1xFL1x_VBatchPosition3dTexTGTexTGCxform;
        break;
      case 285:
      case 286:
      case 317:
      case 318:
      case 333:
      case 334:
      case 365:
      case 366:
        result = VSI_D3D1xFL1x_VInstancedPosition3dTexTGTexTGCxform;
        break;
      case 513:
      case 514:
      case 545:
      case 546:
        result = VSI_D3D1xFL1x_VTexTGVertex;
        break;
      case 515:
      case 516:
      case 547:
      case 548:
        result = VSI_D3D1xFL1x_VBatchTexTGVertex;
        break;
      case 517:
      case 518:
      case 549:
      case 550:
        result = VSI_D3D1xFL1x_VInstancedTexTGVertex;
        break;
      case 521:
      case 522:
      case 553:
      case 554:
        result = VSI_D3D1xFL1x_VPosition3dTexTGVertex;
        break;
      case 523:
      case 524:
      case 555:
      case 556:
        result = VSI_D3D1xFL1x_VBatchPosition3dTexTGVertex;
        break;
      case 525:
      case 526:
      case 557:
      case 558:
        result = VSI_D3D1xFL1x_VInstancedPosition3dTexTGVertex;
        break;
      case 529:
      case 530:
      case 561:
      case 562:
      case 577:
      case 578:
      case 609:
      case 610:
        result = VSI_D3D1xFL1x_VTexTGVertexCxform;
        break;
      case 531:
      case 532:
      case 563:
      case 564:
      case 579:
      case 580:
      case 611:
      case 612:
        result = VSI_D3D1xFL1x_VBatchTexTGVertexCxform;
        break;
      case 533:
      case 534:
      case 565:
      case 566:
      case 581:
      case 582:
      case 613:
      case 614:
        result = VSI_D3D1xFL1x_VInstancedTexTGVertexCxform;
        break;
      case 537:
      case 538:
      case 569:
      case 570:
      case 585:
      case 586:
      case 617:
      case 618:
        result = VSI_D3D1xFL1x_VPosition3dTexTGVertexCxform;
        break;
      case 539:
      case 540:
      case 571:
      case 572:
      case 587:
      case 588:
      case 619:
      case 620:
        result = VSI_D3D1xFL1x_VBatchPosition3dTexTGVertexCxform;
        break;
      case 541:
      case 542:
      case 573:
      case 574:
      case 589:
      case 590:
      case 621:
      case 622:
        result = VSI_D3D1xFL1x_VInstancedPosition3dTexTGVertexCxform;
        break;
      default:
        return 0;
    }
    return result;
  }
  if ( shader <= 5120 )
  {
    if ( shader == 5120 )
      return 206;
    switch ( shader )
    {
      case 4097:
        return 205;
      case 4098:
      case 4099:
        result = VSI_D3D1xFL1x_VBatchSolid;
        break;
      case 4100:
      case 4101:
        result = VSI_D3D1xFL1x_VInstancedSolid;
        break;
      case 4104:
      case 4105:
        result = VSI_D3D1xFL1x_VPosition3dSolid;
        break;
      case 4106:
      case 4107:
        result = VSI_D3D1xFL1x_VBatchPosition3dSolid;
        break;
      case 4108:
      case 4109:
        result = VSI_D3D1xFL1x_VInstancedPosition3dSolid;
        break;
      default:
        return 0;
    }
    return result;
  }
  if ( shader <= 6144 )
  {
    if ( shader == 6144 )
      return 207;
    switch ( shader )
    {
      case 5121:
        return 206;
      case 5122:
      case 5123:
        result = VSI_D3D1xFL1x_VBatchText;
        break;
      case 5124:
      case 5125:
        result = VSI_D3D1xFL1x_VInstancedText;
        break;
      case 5128:
      case 5129:
        result = VSI_D3D1xFL1x_VPosition3dText;
        break;
      case 5130:
      case 5131:
        result = VSI_D3D1xFL1x_VBatchPosition3dText;
        break;
      case 5132:
      case 5133:
        result = VSI_D3D1xFL1x_VInstancedPosition3dText;
        break;
      default:
        return 0;
    }
    return result;
  }
  if ( shader <= 0x2000 )
  {
    if ( shader != 0x2000 )
    {
      switch ( shader )
      {
        case 6145:
          return 207;
        case 6146:
        case 6147:
          result = VSI_D3D1xFL1x_VBatchTextColor;
          break;
        case 6148:
        case 6149:
          result = VSI_D3D1xFL1x_VInstancedTextColor;
          break;
        case 6152:
        case 6153:
          result = VSI_D3D1xFL1x_VPosition3dTextColor;
          break;
        case 6154:
        case 6155:
          result = VSI_D3D1xFL1x_VBatchPosition3dTextColor;
          break;
        case 6156:
        case 6157:
          result = VSI_D3D1xFL1x_VInstancedPosition3dTextColor;
          break;
        case 6160:
        case 6161:
          result = VSI_D3D1xFL1x_VTextColorCxform;
          break;
        case 6162:
        case 6163:
          result = VSI_D3D1xFL1x_VBatchTextColorCxform;
          break;
        case 6164:
        case 6165:
          result = VSI_D3D1xFL1x_VInstancedTextColorCxform;
          break;
        case 6168:
        case 6169:
          result = VSI_D3D1xFL1x_VPosition3dTextColorCxform;
          break;
        case 6170:
        case 6171:
          result = VSI_D3D1xFL1x_VBatchPosition3dTextColorCxform;
          break;
        case 6172:
        case 6173:
          result = VSI_D3D1xFL1x_VInstancedPosition3dTextColorCxform;
          break;
        default:
          return 0;
      }
      return result;
    }
    return 133;
  }
  if ( shader <= 10240 )
  {
    if ( shader != 10240 )
    {
      switch ( shader )
      {
        case 8193:
          return 133;
        case 8194:
        case 8195:
          goto $LN183_0;
        case 8196:
        case 8197:
          goto $LN517_0;
        case 8200:
        case 8201:
          goto $LN515;
        case 8202:
        case 8203:
          goto $LN513;
        case 8204:
        case 8205:
          goto $LN511;
        case 8208:
        case 8209:
        case 8256:
        case 8257:
          goto $LN509_0;
        case 8210:
        case 8211:
        case 8258:
        case 8259:
          goto $LN507_0;
        case 8212:
        case 8213:
        case 8260:
        case 8261:
          goto $LN505_0;
        case 8216:
        case 8217:
        case 8264:
        case 8265:
          goto $LN503;
        case 8218:
        case 8219:
        case 8266:
        case 8267:
          goto $LN501;
        case 8220:
        case 8221:
        case 8268:
        case 8269:
          goto $LN499;
        case 8224:
        case 8225:
          return 134;
        case 8226:
        case 8227:
          goto $LN495_0;
        case 8228:
        case 8229:
          goto $LN493_0;
        case 8232:
        case 8233:
          goto $LN491;
        case 8234:
        case 8235:
          goto $LN489;
        case 8236:
        case 8237:
          goto $LN487;
        case 8240:
        case 8241:
        case 8288:
        case 8289:
          goto $LN485_0;
        case 8242:
        case 8243:
        case 8290:
        case 8291:
          goto $LN483_1;
        case 8244:
        case 8245:
        case 8292:
        case 8293:
          goto $LN481_0;
        case 8248:
        case 8249:
        case 8296:
        case 8297:
          goto $LN479;
        case 8250:
        case 8251:
        case 8298:
        case 8299:
          goto $LN477;
        case 8252:
        case 8253:
        case 8300:
        case 8301:
          goto $LN475;
        default:
          return 0;
      }
    }
    return 133;
  }
  if ( shader > 12288 )
  {
    if ( shader > 21520 )
    {
      if ( shader > 24576 )
      {
        if ( shader > 28672 )
        {
          if ( shader != 0x8000 )
          {
            if ( shader != 36864 )
              return 0;
            return 133;
          }
        }
        else if ( shader != 28672 )
        {
          switch ( shader )
          {
            case 24577:
            case 24578:
              return 230;
            case 24580:
            case 24581:
            case 24582:
              result = VSI_D3D1xFL1x_VDrawableCopyPixelsAlpha;
              break;
            default:
              return 0;
          }
          return result;
        }
      }
      else if ( shader != 24576 )
      {
        switch ( shader )
        {
          case 21521:
          case 21536:
          case 21537:
          case 21568:
          case 21569:
          case 21576:
          case 21577:
          case 21632:
          case 21633:
          case 21640:
          case 21641:
            return 229;
          default:
            return 0;
        }
      }
      return 230;
    }
    if ( shader == 21520 )
      return 229;
    if ( shader > 20481 )
    {
      if ( shader <= 20992 )
      {
        if ( shader != 20992 )
        {
          switch ( shader )
          {
            case 20488:
            case 20489:
            case 20736:
            case 20737:
              return 229;
            default:
              return 0;
          }
        }
        return 229;
      }
      v8 = shader - 20993;
      if ( !v8 )
        return 229;
      v9 = v8 - 7;
      if ( !v9 )
        return 229;
      v5 = v9 == 1;
    }
    else
    {
      if ( shader == 20481 )
        return 229;
      if ( shader > 16385 )
      {
        v6 = shader - 18432;
        if ( v6 )
        {
          v7 = v6 - 1;
          if ( v7 )
          {
            if ( v7 == 2047 )
              return 229;
            return 0;
          }
        }
        return 229;
      }
      if ( shader == 16385 )
        return 229;
      if ( shader <= 12321 )
      {
        if ( shader == 12321 )
          return 134;
        v4 = shader - 12289;
        if ( !v4 )
          return 133;
        if ( v4 == 31 )
          return 134;
        return 0;
      }
      v5 = shader == 0x4000;
    }
    if ( !v5 )
      return 0;
    return 229;
  }
  if ( shader == 12288 )
    return 133;
  switch ( shader )
  {
    case 10241:
      return 133;
    case 10242:
    case 10243:
$LN183_0:
      result = VSI_D3D1xFL1x_VBatchTexTG;
      break;
    case 10244:
    case 10245:
$LN517_0:
      result = VSI_D3D1xFL1x_VInstancedTexTG;
      break;
    case 10248:
    case 10249:
$LN515:
      result = VSI_D3D1xFL1x_VPosition3dTexTG;
      break;
    case 10250:
    case 10251:
$LN513:
      result = VSI_D3D1xFL1x_VBatchPosition3dTexTG;
      break;
    case 10252:
    case 10253:
$LN511:
      result = VSI_D3D1xFL1x_VInstancedPosition3dTexTG;
      break;
    case 10256:
    case 10257:
    case 10304:
    case 10305:
$LN509_0:
      result = VSI_D3D1xFL1x_VTexTGCxform;
      break;
    case 10258:
    case 10259:
    case 10306:
    case 10307:
$LN507_0:
      result = VSI_D3D1xFL1x_VBatchTexTGCxform;
      break;
    case 10260:
    case 10261:
    case 10308:
    case 10309:
$LN505_0:
      result = VSI_D3D1xFL1x_VInstancedTexTGCxform;
      break;
    case 10264:
    case 10265:
    case 10312:
    case 10313:
$LN503:
      result = VSI_D3D1xFL1x_VPosition3dTexTGCxform;
      break;
    case 10266:
    case 10267:
    case 10314:
    case 10315:
$LN501:
      result = VSI_D3D1xFL1x_VBatchPosition3dTexTGCxform;
      break;
    case 10268:
    case 10269:
    case 10316:
    case 10317:
$LN499:
      result = VSI_D3D1xFL1x_VInstancedPosition3dTexTGCxform;
      break;
    case 10272:
    case 10273:
      return 134;
    case 10274:
    case 10275:
$LN495_0:
      result = VSI_D3D1xFL1x_VBatchTexTGEAlpha;
      break;
    case 10276:
    case 10277:
$LN493_0:
      result = VSI_D3D1xFL1x_VInstancedTexTGEAlpha;
      break;
    case 10280:
    case 10281:
$LN491:
      result = VSI_D3D1xFL1x_VPosition3dTexTGEAlpha;
      break;
    case 10282:
    case 10283:
$LN489:
      result = VSI_D3D1xFL1x_VBatchPosition3dTexTGEAlpha;
      break;
    case 10284:
    case 10285:
$LN487:
      result = VSI_D3D1xFL1x_VInstancedPosition3dTexTGEAlpha;
      break;
    case 10288:
    case 10289:
    case 10336:
    case 10337:
$LN485_0:
      result = VSI_D3D1xFL1x_VTexTGCxformEAlpha;
      break;
    case 10290:
    case 10291:
    case 10338:
    case 10339:
$LN483_1:
      result = VSI_D3D1xFL1x_VBatchTexTGCxformEAlpha;
      break;
    case 10292:
    case 10293:
    case 10340:
    case 10341:
$LN481_0:
      result = VSI_D3D1xFL1x_VInstancedTexTGCxformEAlpha;
      break;
    case 10296:
    case 10297:
    case 10344:
    case 10345:
$LN479:
      result = VSI_D3D1xFL1x_VPosition3dTexTGCxformEAlpha;
      break;
    case 10298:
    case 10299:
    case 10346:
    case 10347:
$LN477:
      result = VSI_D3D1xFL1x_VBatchPosition3dTexTGCxformEAlpha;
      break;
    case 10300:
    case 10301:
    case 10348:
    case 10349:
$LN475:
      result = VSI_D3D1xFL1x_VInstancedPosition3dTexTGCxformEAlpha;
      break;
    default:
      return 0;
  }
  return result;
}
