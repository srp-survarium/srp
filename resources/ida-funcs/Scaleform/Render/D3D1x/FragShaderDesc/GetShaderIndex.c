Scaleform::Render::D3D1x::FragShaderDesc::ShaderIndex __usercall Scaleform::Render::D3D1x::FragShaderDesc::GetShaderIndex@<eax>(
        int shader@<ecx>,
        Scaleform::Render::D3D1x::ShaderDesc::ShaderVersion ver@<eax>)
{
  int v2; // eax
  Scaleform::Render::D3D1x::FragShaderDesc::ShaderIndex result; // eax
  int v4; // ecx
  int v5; // ecx
  int v6; // ecx
  int v7; // ecx
  int v8; // ecx
  int v9; // ecx
  int v10; // ecx
  int v11; // ecx
  int v12; // ecx
  int v13; // ecx
  int v14; // ecx
  int v15; // ecx
  int v16; // ecx
  int v17; // ecx
  int v18; // ecx
  int v19; // ecx
  int v20; // ecx
  int v21; // ecx
  int v22; // ecx
  int v23; // ecx
  int v24; // ecx
  unsigned int v25; // ecx
  int v26; // ecx
  int v27; // ecx
  int v28; // ecx
  int v29; // ecx
  int v30; // ecx
  int v31; // ecx
  int v32; // ecx
  int v33; // ecx
  int v34; // ecx
  int v35; // ecx

  if ( ver )
  {
    v2 = ver - 1;
    if ( v2 )
    {
      if ( v2 == 1 )
      {
        if ( shader <= 4096 )
        {
          if ( shader == 4096 )
            return 475;
          if ( shader > 257 )
          {
            result = FSI_D3D1xFL1x_FTexTGTexTGCxformAcMul;
            switch ( shader )
            {
              case 258:
              case 266:
                result = FSI_D3D1xFL1x_FTexTGTexTGMul;
                break;
              case 259:
              case 267:
                result = FSI_D3D1xFL1x_FBatchTexTGTexTG;
                break;
              case 260:
              case 268:
                result = FSI_D3D1xFL1x_FBatchTexTGTexTGMul;
                break;
              case 261:
              case 269:
                result = FSI_D3D1xFL1x_FInstancedTexTGTexTG;
                break;
              case 262:
              case 270:
                result = FSI_D3D1xFL1x_FInstancedTexTGTexTGMul;
                break;
              case 265:
                return 355;
              case 273:
              case 281:
                result = FSI_D3D1xFL1x_FTexTGTexTGCxform;
                break;
              case 274:
              case 282:
                result = FSI_D3D1xFL1x_FTexTGTexTGCxformMul;
                break;
              case 275:
              case 283:
                result = FSI_D3D1xFL1x_FBatchTexTGTexTGCxform;
                break;
              case 276:
              case 284:
                result = FSI_D3D1xFL1x_FBatchTexTGTexTGCxformMul;
                break;
              case 277:
              case 285:
                result = FSI_D3D1xFL1x_FInstancedTexTGTexTGCxform;
                break;
              case 278:
              case 286:
                result = FSI_D3D1xFL1x_FInstancedTexTGTexTGCxformMul;
                break;
              case 289:
              case 297:
                result = FSI_D3D1xFL1x_FTexTGTexTGEAlpha;
                break;
              case 290:
              case 298:
                result = FSI_D3D1xFL1x_FTexTGTexTGEAlphaMul;
                break;
              case 291:
              case 299:
                result = FSI_D3D1xFL1x_FBatchTexTGTexTGEAlpha;
                break;
              case 292:
              case 300:
                result = FSI_D3D1xFL1x_FBatchTexTGTexTGEAlphaMul;
                break;
              case 293:
              case 301:
                result = FSI_D3D1xFL1x_FInstancedTexTGTexTGEAlpha;
                break;
              case 294:
              case 302:
                result = FSI_D3D1xFL1x_FInstancedTexTGTexTGEAlphaMul;
                break;
              case 305:
              case 313:
                result = FSI_D3D1xFL1x_FTexTGTexTGCxformEAlpha;
                break;
              case 306:
              case 314:
                result = FSI_D3D1xFL1x_FTexTGTexTGCxformEAlphaMul;
                break;
              case 307:
              case 315:
                result = FSI_D3D1xFL1x_FBatchTexTGTexTGCxformEAlpha;
                break;
              case 308:
              case 316:
                result = FSI_D3D1xFL1x_FBatchTexTGTexTGCxformEAlphaMul;
                break;
              case 309:
              case 317:
                result = FSI_D3D1xFL1x_FInstancedTexTGTexTGCxformEAlpha;
                break;
              case 310:
              case 318:
                result = FSI_D3D1xFL1x_FInstancedTexTGTexTGCxformEAlphaMul;
                break;
              case 321:
              case 329:
                result = FSI_D3D1xFL1x_FTexTGTexTGCxformAc;
                break;
              case 322:
              case 330:
                return result;
              case 323:
              case 331:
                result = FSI_D3D1xFL1x_FBatchTexTGTexTGCxformAc;
                break;
              case 324:
              case 332:
                result = FSI_D3D1xFL1x_FBatchTexTGTexTGCxformAcMul;
                break;
              case 325:
              case 333:
                result = FSI_D3D1xFL1x_FInstancedTexTGTexTGCxformAc;
                break;
              case 326:
              case 334:
                result = FSI_D3D1xFL1x_FInstancedTexTGTexTGCxformAcMul;
                break;
              case 353:
              case 361:
                result = FSI_D3D1xFL1x_FTexTGTexTGCxformAcEAlpha;
                break;
              case 354:
              case 362:
                result = FSI_D3D1xFL1x_FTexTGTexTGCxformAcEAlphaMul;
                break;
              case 355:
              case 363:
                result = FSI_D3D1xFL1x_FBatchTexTGTexTGCxformAcEAlpha;
                break;
              case 356:
              case 364:
                result = FSI_D3D1xFL1x_FBatchTexTGTexTGCxformAcEAlphaMul;
                break;
              case 357:
              case 365:
                result = FSI_D3D1xFL1x_FInstancedTexTGTexTGCxformAcEAlpha;
                break;
              case 358:
              case 366:
                result = FSI_D3D1xFL1x_FInstancedTexTGTexTGCxformAcEAlphaMul;
                break;
              case 513:
              case 521:
                result = FSI_D3D1xFL1x_FTexTGVertex;
                break;
              case 514:
              case 522:
                result = FSI_D3D1xFL1x_FTexTGVertexMul;
                break;
              case 515:
              case 523:
                result = FSI_D3D1xFL1x_FBatchTexTGVertex;
                break;
              case 516:
              case 524:
                result = FSI_D3D1xFL1x_FBatchTexTGVertexMul;
                break;
              case 517:
              case 525:
                result = FSI_D3D1xFL1x_FInstancedTexTGVertex;
                break;
              case 518:
              case 526:
                result = FSI_D3D1xFL1x_FInstancedTexTGVertexMul;
                break;
              case 529:
              case 537:
                result = FSI_D3D1xFL1x_FTexTGVertexCxform;
                break;
              case 530:
              case 538:
                result = FSI_D3D1xFL1x_FTexTGVertexCxformMul;
                break;
              case 531:
              case 539:
                result = FSI_D3D1xFL1x_FBatchTexTGVertexCxform;
                break;
              case 532:
              case 540:
                result = FSI_D3D1xFL1x_FBatchTexTGVertexCxformMul;
                break;
              case 533:
              case 541:
                result = FSI_D3D1xFL1x_FInstancedTexTGVertexCxform;
                break;
              case 534:
              case 542:
                result = FSI_D3D1xFL1x_FInstancedTexTGVertexCxformMul;
                break;
              case 545:
              case 553:
                result = FSI_D3D1xFL1x_FTexTGVertexEAlpha;
                break;
              case 546:
              case 554:
                result = FSI_D3D1xFL1x_FTexTGVertexEAlphaMul;
                break;
              case 547:
              case 555:
                result = FSI_D3D1xFL1x_FBatchTexTGVertexEAlpha;
                break;
              case 548:
              case 556:
                result = FSI_D3D1xFL1x_FBatchTexTGVertexEAlphaMul;
                break;
              case 549:
              case 557:
                result = FSI_D3D1xFL1x_FInstancedTexTGVertexEAlpha;
                break;
              case 550:
              case 558:
                result = FSI_D3D1xFL1x_FInstancedTexTGVertexEAlphaMul;
                break;
              case 561:
              case 569:
                result = FSI_D3D1xFL1x_FTexTGVertexCxformEAlpha;
                break;
              case 562:
              case 570:
                result = FSI_D3D1xFL1x_FTexTGVertexCxformEAlphaMul;
                break;
              case 563:
              case 571:
                result = FSI_D3D1xFL1x_FBatchTexTGVertexCxformEAlpha;
                break;
              case 564:
              case 572:
                result = FSI_D3D1xFL1x_FBatchTexTGVertexCxformEAlphaMul;
                break;
              case 565:
              case 573:
                result = FSI_D3D1xFL1x_FInstancedTexTGVertexCxformEAlpha;
                break;
              case 566:
              case 574:
                result = FSI_D3D1xFL1x_FInstancedTexTGVertexCxformEAlphaMul;
                break;
              case 577:
              case 585:
                result = FSI_D3D1xFL1x_FTexTGVertexCxformAc;
                break;
              case 578:
              case 586:
                result = FSI_D3D1xFL1x_FTexTGVertexCxformAcMul;
                break;
              case 579:
              case 587:
                result = FSI_D3D1xFL1x_FBatchTexTGVertexCxformAc;
                break;
              case 580:
              case 588:
                result = FSI_D3D1xFL1x_FBatchTexTGVertexCxformAcMul;
                break;
              case 581:
              case 589:
                result = FSI_D3D1xFL1x_FInstancedTexTGVertexCxformAc;
                break;
              case 582:
              case 590:
                result = FSI_D3D1xFL1x_FInstancedTexTGVertexCxformAcMul;
                break;
              case 609:
              case 617:
                result = FSI_D3D1xFL1x_FTexTGVertexCxformAcEAlpha;
                break;
              case 610:
              case 618:
                result = FSI_D3D1xFL1x_FTexTGVertexCxformAcEAlphaMul;
                break;
              case 611:
              case 619:
                result = FSI_D3D1xFL1x_FBatchTexTGVertexCxformAcEAlpha;
                break;
              case 612:
              case 620:
                result = FSI_D3D1xFL1x_FBatchTexTGVertexCxformAcEAlphaMul;
                break;
              case 613:
              case 621:
                result = FSI_D3D1xFL1x_FInstancedTexTGVertexCxformAcEAlpha;
                break;
              case 614:
              case 622:
                result = FSI_D3D1xFL1x_FInstancedTexTGVertexCxformAcEAlphaMul;
                break;
              default:
                return 0;
            }
          }
          else if ( shader == 257 )
          {
            return 355;
          }
          else
          {
            switch ( shader )
            {
              case 1:
              case 9:
                return 331;
              case 2:
              case 10:
                goto $LN520;
              case 3:
              case 11:
                goto $LN519_0;
              case 4:
              case 12:
                goto $LN518;
              case 5:
              case 13:
                goto $LN517_0;
              case 6:
              case 14:
                goto $LN516;
              case 17:
              case 25:
                goto $LN509_0;
              case 18:
              case 26:
                goto $LN508;
              case 19:
              case 27:
                goto $LN507_0;
              case 20:
              case 28:
                goto $LN506;
              case 21:
              case 29:
                goto $LN505_0;
              case 22:
              case 30:
                goto $LN504;
              case 33:
              case 41:
                result = FSI_D3D1xFL1x_FTexTGEAlpha;
                break;
              case 34:
              case 42:
                result = FSI_D3D1xFL1x_FTexTGEAlphaMul;
                break;
              case 35:
              case 43:
                result = FSI_D3D1xFL1x_FBatchTexTGEAlpha;
                break;
              case 36:
              case 44:
                result = FSI_D3D1xFL1x_FBatchTexTGEAlphaMul;
                break;
              case 37:
              case 45:
                result = FSI_D3D1xFL1x_FInstancedTexTGEAlpha;
                break;
              case 38:
              case 46:
                result = FSI_D3D1xFL1x_FInstancedTexTGEAlphaMul;
                break;
              case 49:
              case 57:
                result = FSI_D3D1xFL1x_FTexTGCxformEAlpha;
                break;
              case 50:
              case 58:
                result = FSI_D3D1xFL1x_FTexTGCxformEAlphaMul;
                break;
              case 51:
              case 59:
                result = FSI_D3D1xFL1x_FBatchTexTGCxformEAlpha;
                break;
              case 52:
              case 60:
                result = FSI_D3D1xFL1x_FBatchTexTGCxformEAlphaMul;
                break;
              case 53:
              case 61:
                result = FSI_D3D1xFL1x_FInstancedTexTGCxformEAlpha;
                break;
              case 54:
              case 62:
                result = FSI_D3D1xFL1x_FInstancedTexTGCxformEAlphaMul;
                break;
              case 65:
              case 73:
                result = FSI_D3D1xFL1x_FTexTGCxformAc;
                break;
              case 66:
              case 74:
                result = FSI_D3D1xFL1x_FTexTGCxformAcMul;
                break;
              case 67:
              case 75:
                result = FSI_D3D1xFL1x_FBatchTexTGCxformAc;
                break;
              case 68:
              case 76:
                result = FSI_D3D1xFL1x_FBatchTexTGCxformAcMul;
                break;
              case 69:
              case 77:
                result = FSI_D3D1xFL1x_FInstancedTexTGCxformAc;
                break;
              case 70:
              case 78:
                result = FSI_D3D1xFL1x_FInstancedTexTGCxformAcMul;
                break;
              case 97:
              case 105:
                result = FSI_D3D1xFL1x_FTexTGCxformAcEAlpha;
                break;
              case 98:
              case 106:
                result = FSI_D3D1xFL1x_FTexTGCxformAcEAlphaMul;
                break;
              case 99:
              case 107:
                result = FSI_D3D1xFL1x_FBatchTexTGCxformAcEAlpha;
                break;
              case 100:
              case 108:
                result = FSI_D3D1xFL1x_FBatchTexTGCxformAcEAlphaMul;
                break;
              case 101:
              case 109:
                result = FSI_D3D1xFL1x_FInstancedTexTGCxformAcEAlpha;
                break;
              case 102:
              case 110:
                result = FSI_D3D1xFL1x_FInstancedTexTGCxformAcEAlphaMul;
                break;
              case 129:
              case 137:
                result = FSI_D3D1xFL1x_FVertex;
                break;
              case 130:
              case 138:
                result = FSI_D3D1xFL1x_FVertexMul;
                break;
              case 131:
              case 139:
                result = FSI_D3D1xFL1x_FBatchVertex;
                break;
              case 132:
              case 140:
                result = FSI_D3D1xFL1x_FBatchVertexMul;
                break;
              case 133:
              case 141:
                result = FSI_D3D1xFL1x_FInstancedVertex;
                break;
              case 134:
              case 142:
                result = FSI_D3D1xFL1x_FInstancedVertexMul;
                break;
              case 145:
              case 153:
                result = FSI_D3D1xFL1x_FVertexCxform;
                break;
              case 146:
              case 154:
                result = FSI_D3D1xFL1x_FVertexCxformMul;
                break;
              case 147:
              case 155:
                result = FSI_D3D1xFL1x_FBatchVertexCxform;
                break;
              case 148:
              case 156:
                result = FSI_D3D1xFL1x_FBatchVertexCxformMul;
                break;
              case 149:
              case 157:
                result = FSI_D3D1xFL1x_FInstancedVertexCxform;
                break;
              case 150:
              case 158:
                result = FSI_D3D1xFL1x_FInstancedVertexCxformMul;
                break;
              case 161:
              case 169:
                result = FSI_D3D1xFL1x_FVertexEAlpha;
                break;
              case 162:
              case 170:
                result = FSI_D3D1xFL1x_FVertexEAlphaMul;
                break;
              case 163:
              case 171:
                result = FSI_D3D1xFL1x_FBatchVertexEAlpha;
                break;
              case 164:
              case 172:
                result = FSI_D3D1xFL1x_FBatchVertexEAlphaMul;
                break;
              case 165:
              case 173:
                result = FSI_D3D1xFL1x_FInstancedVertexEAlpha;
                break;
              case 166:
              case 174:
                result = FSI_D3D1xFL1x_FInstancedVertexEAlphaMul;
                break;
              case 177:
              case 185:
                result = FSI_D3D1xFL1x_FVertexCxformEAlpha;
                break;
              case 178:
              case 186:
                result = FSI_D3D1xFL1x_FVertexCxformEAlphaMul;
                break;
              case 179:
              case 187:
                result = FSI_D3D1xFL1x_FBatchVertexCxformEAlpha;
                break;
              case 180:
              case 188:
                result = FSI_D3D1xFL1x_FBatchVertexCxformEAlphaMul;
                break;
              case 181:
              case 189:
                result = FSI_D3D1xFL1x_FInstancedVertexCxformEAlpha;
                break;
              case 182:
              case 190:
                result = FSI_D3D1xFL1x_FInstancedVertexCxformEAlphaMul;
                break;
              case 193:
              case 201:
                result = FSI_D3D1xFL1x_FVertexCxformAc;
                break;
              case 194:
              case 202:
                result = FSI_D3D1xFL1x_FVertexCxformAcMul;
                break;
              case 195:
              case 203:
                result = FSI_D3D1xFL1x_FBatchVertexCxformAc;
                break;
              case 196:
              case 204:
                result = FSI_D3D1xFL1x_FBatchVertexCxformAcMul;
                break;
              case 197:
              case 205:
                result = FSI_D3D1xFL1x_FInstancedVertexCxformAc;
                break;
              case 198:
              case 206:
                result = FSI_D3D1xFL1x_FInstancedVertexCxformAcMul;
                break;
              case 225:
              case 233:
                result = FSI_D3D1xFL1x_FVertexCxformAcEAlpha;
                break;
              case 226:
              case 234:
                result = FSI_D3D1xFL1x_FVertexCxformAcEAlphaMul;
                break;
              case 227:
              case 235:
                result = FSI_D3D1xFL1x_FBatchVertexCxformAcEAlpha;
                break;
              case 228:
              case 236:
                result = FSI_D3D1xFL1x_FBatchVertexCxformAcEAlphaMul;
                break;
              case 229:
              case 237:
                result = FSI_D3D1xFL1x_FInstancedVertexCxformAcEAlpha;
                break;
              case 230:
              case 238:
                result = FSI_D3D1xFL1x_FInstancedVertexCxformAcEAlphaMul;
                break;
              default:
                return 0;
            }
          }
          return result;
        }
        if ( shader <= 5120 )
        {
          if ( shader == 5120 )
            return 477;
          switch ( shader )
          {
            case 4097:
            case 4105:
              result = FSI_D3D1xFL1x_FSolidMul;
              break;
            case 4098:
            case 4106:
              result = FSI_D3D1xFL1x_FBatchSolid;
              break;
            case 4099:
            case 4107:
              result = FSI_D3D1xFL1x_FBatchSolidMul;
              break;
            case 4100:
            case 4108:
              result = FSI_D3D1xFL1x_FInstancedSolid;
              break;
            case 4101:
            case 4109:
              result = FSI_D3D1xFL1x_FInstancedSolidMul;
              break;
            case 4104:
              return 475;
            default:
              return 0;
          }
          return result;
        }
        if ( shader <= 6144 )
        {
          if ( shader == 6144 )
            return 331;
          switch ( shader )
          {
            case 5121:
            case 5129:
              result = FSI_D3D1xFL1x_FTextMul;
              break;
            case 5122:
            case 5130:
              result = FSI_D3D1xFL1x_FBatchText;
              break;
            case 5123:
            case 5131:
              result = FSI_D3D1xFL1x_FBatchTextMul;
              break;
            case 5124:
            case 5132:
              result = FSI_D3D1xFL1x_FInstancedText;
              break;
            case 5125:
            case 5133:
              result = FSI_D3D1xFL1x_FInstancedTextMul;
              break;
            case 5128:
              return 477;
            default:
              return 0;
          }
          return result;
        }
        if ( shader <= 0x2000 )
        {
          if ( shader == 0x2000 )
            return 487;
          switch ( shader )
          {
            case 6145:
            case 6153:
$LN520:
              result = FSI_D3D1xFL1x_FTexTGMul;
              break;
            case 6146:
            case 6154:
$LN519_0:
              result = FSI_D3D1xFL1x_FBatchTexTG;
              break;
            case 6147:
            case 6155:
$LN518:
              result = FSI_D3D1xFL1x_FBatchTexTGMul;
              break;
            case 6148:
            case 6156:
$LN517_0:
              result = FSI_D3D1xFL1x_FInstancedTexTG;
              break;
            case 6149:
            case 6157:
$LN516:
              result = FSI_D3D1xFL1x_FInstancedTexTGMul;
              break;
            case 6152:
              return 331;
            case 6160:
            case 6168:
$LN509_0:
              result = FSI_D3D1xFL1x_FTexTGCxform;
              break;
            case 6161:
            case 6169:
$LN508:
              result = FSI_D3D1xFL1x_FTexTGCxformMul;
              break;
            case 6162:
            case 6170:
$LN507_0:
              result = FSI_D3D1xFL1x_FBatchTexTGCxform;
              break;
            case 6163:
            case 6171:
$LN506:
              result = FSI_D3D1xFL1x_FBatchTexTGCxformMul;
              break;
            case 6164:
            case 6172:
$LN505_0:
              result = FSI_D3D1xFL1x_FInstancedTexTGCxform;
              break;
            case 6165:
            case 6173:
$LN504:
              result = FSI_D3D1xFL1x_FInstancedTexTGCxformMul;
              break;
            default:
              return 0;
          }
          return result;
        }
        if ( shader <= 10240 )
        {
          if ( shader == 10240 )
            return 499;
          switch ( shader )
          {
            case 8193:
            case 8201:
              result = FSI_D3D1xFL1x_FYUVMul;
              break;
            case 8194:
            case 8202:
              result = FSI_D3D1xFL1x_FBatchYUV;
              break;
            case 8195:
            case 8203:
              result = FSI_D3D1xFL1x_FBatchYUVMul;
              break;
            case 8196:
            case 8204:
              result = FSI_D3D1xFL1x_FInstancedYUV;
              break;
            case 8197:
            case 8205:
              result = FSI_D3D1xFL1x_FInstancedYUVMul;
              break;
            case 8200:
              return 487;
            case 8208:
            case 8216:
              result = FSI_D3D1xFL1x_FYUVCxform;
              break;
            case 8209:
            case 8217:
              result = FSI_D3D1xFL1x_FYUVCxformMul;
              break;
            case 8210:
            case 8218:
              result = FSI_D3D1xFL1x_FBatchYUVCxform;
              break;
            case 8211:
            case 8219:
              result = FSI_D3D1xFL1x_FBatchYUVCxformMul;
              break;
            case 8212:
            case 8220:
              result = FSI_D3D1xFL1x_FInstancedYUVCxform;
              break;
            case 8213:
            case 8221:
              result = FSI_D3D1xFL1x_FInstancedYUVCxformMul;
              break;
            case 8224:
            case 8232:
              result = FSI_D3D1xFL1x_FYUVEAlpha;
              break;
            case 8225:
            case 8233:
              result = FSI_D3D1xFL1x_FYUVEAlphaMul;
              break;
            case 8226:
            case 8234:
              result = FSI_D3D1xFL1x_FBatchYUVEAlpha;
              break;
            case 8227:
            case 8235:
              result = FSI_D3D1xFL1x_FBatchYUVEAlphaMul;
              break;
            case 8228:
            case 8236:
              result = FSI_D3D1xFL1x_FInstancedYUVEAlpha;
              break;
            case 8229:
            case 8237:
              result = FSI_D3D1xFL1x_FInstancedYUVEAlphaMul;
              break;
            case 8240:
            case 8248:
              result = FSI_D3D1xFL1x_FYUVCxformEAlpha;
              break;
            case 8241:
            case 8249:
              result = FSI_D3D1xFL1x_FYUVCxformEAlphaMul;
              break;
            case 8242:
            case 8250:
              result = FSI_D3D1xFL1x_FBatchYUVCxformEAlpha;
              break;
            case 8243:
            case 8251:
              result = FSI_D3D1xFL1x_FBatchYUVCxformEAlphaMul;
              break;
            case 8244:
            case 8252:
              result = FSI_D3D1xFL1x_FInstancedYUVCxformEAlpha;
              break;
            case 8245:
            case 8253:
              result = FSI_D3D1xFL1x_FInstancedYUVCxformEAlphaMul;
              break;
            case 8256:
            case 8264:
              result = FSI_D3D1xFL1x_FYUVCxformAc;
              break;
            case 8257:
            case 8265:
              result = FSI_D3D1xFL1x_FYUVCxformAcMul;
              break;
            case 8258:
            case 8266:
              result = FSI_D3D1xFL1x_FBatchYUVCxformAc;
              break;
            case 8259:
            case 8267:
              result = FSI_D3D1xFL1x_FBatchYUVCxformAcMul;
              break;
            case 8260:
            case 8268:
              result = FSI_D3D1xFL1x_FInstancedYUVCxformAc;
              break;
            case 8261:
            case 8269:
              result = FSI_D3D1xFL1x_FInstancedYUVCxformAcMul;
              break;
            case 8288:
            case 8296:
              result = FSI_D3D1xFL1x_FYUVCxformAcEAlpha;
              break;
            case 8289:
            case 8297:
              result = FSI_D3D1xFL1x_FYUVCxformAcEAlphaMul;
              break;
            case 8290:
            case 8298:
              result = FSI_D3D1xFL1x_FBatchYUVCxformAcEAlpha;
              break;
            case 8291:
            case 8299:
              result = FSI_D3D1xFL1x_FBatchYUVCxformAcEAlphaMul;
              break;
            case 8292:
            case 8300:
              result = FSI_D3D1xFL1x_FInstancedYUVCxformAcEAlpha;
              break;
            case 8293:
            case 8301:
              result = FSI_D3D1xFL1x_FInstancedYUVCxformAcEAlphaMul;
              break;
            default:
              return 0;
          }
          return result;
        }
        if ( shader <= 12288 )
        {
          if ( shader == 12288 )
            return 559;
          switch ( shader )
          {
            case 10241:
            case 10249:
              result = FSI_D3D1xFL1x_FYUVAMul;
              break;
            case 10242:
            case 10250:
              result = FSI_D3D1xFL1x_FBatchYUVA;
              break;
            case 10243:
            case 10251:
              result = FSI_D3D1xFL1x_FBatchYUVAMul;
              break;
            case 10244:
            case 10252:
              result = FSI_D3D1xFL1x_FInstancedYUVA;
              break;
            case 10245:
            case 10253:
              result = FSI_D3D1xFL1x_FInstancedYUVAMul;
              break;
            case 10248:
              return 499;
            case 10256:
            case 10264:
              result = FSI_D3D1xFL1x_FYUVACxform;
              break;
            case 10257:
            case 10265:
              result = FSI_D3D1xFL1x_FYUVACxformMul;
              break;
            case 10258:
            case 10266:
              result = FSI_D3D1xFL1x_FBatchYUVACxform;
              break;
            case 10259:
            case 10267:
              result = FSI_D3D1xFL1x_FBatchYUVACxformMul;
              break;
            case 10260:
            case 10268:
              result = FSI_D3D1xFL1x_FInstancedYUVACxform;
              break;
            case 10261:
            case 10269:
              result = FSI_D3D1xFL1x_FInstancedYUVACxformMul;
              break;
            case 10272:
            case 10280:
              result = FSI_D3D1xFL1x_FYUVAEAlpha;
              break;
            case 10273:
            case 10281:
              result = FSI_D3D1xFL1x_FYUVAEAlphaMul;
              break;
            case 10274:
            case 10282:
              result = FSI_D3D1xFL1x_FBatchYUVAEAlpha;
              break;
            case 10275:
            case 10283:
              result = FSI_D3D1xFL1x_FBatchYUVAEAlphaMul;
              break;
            case 10276:
            case 10284:
              result = FSI_D3D1xFL1x_FInstancedYUVAEAlpha;
              break;
            case 10277:
            case 10285:
              result = FSI_D3D1xFL1x_FInstancedYUVAEAlphaMul;
              break;
            case 10288:
            case 10296:
              result = FSI_D3D1xFL1x_FYUVACxformEAlpha;
              break;
            case 10289:
            case 10297:
              result = FSI_D3D1xFL1x_FYUVACxformEAlphaMul;
              break;
            case 10290:
            case 10298:
              result = FSI_D3D1xFL1x_FBatchYUVACxformEAlpha;
              break;
            case 10291:
            case 10299:
              result = FSI_D3D1xFL1x_FBatchYUVACxformEAlphaMul;
              break;
            case 10292:
            case 10300:
              result = FSI_D3D1xFL1x_FInstancedYUVACxformEAlpha;
              break;
            case 10293:
            case 10301:
              result = FSI_D3D1xFL1x_FInstancedYUVACxformEAlphaMul;
              break;
            case 10304:
            case 10312:
              result = FSI_D3D1xFL1x_FYUVACxformAc;
              break;
            case 10305:
            case 10313:
              result = FSI_D3D1xFL1x_FYUVACxformAcMul;
              break;
            case 10306:
            case 10314:
              result = FSI_D3D1xFL1x_FBatchYUVACxformAc;
              break;
            case 10307:
            case 10315:
              result = FSI_D3D1xFL1x_FBatchYUVACxformAcMul;
              break;
            case 10308:
            case 10316:
              result = FSI_D3D1xFL1x_FInstancedYUVACxformAc;
              break;
            case 10309:
            case 10317:
              result = FSI_D3D1xFL1x_FInstancedYUVACxformAcMul;
              break;
            case 10336:
            case 10344:
              result = FSI_D3D1xFL1x_FYUVACxformAcEAlpha;
              break;
            case 10337:
            case 10345:
              result = FSI_D3D1xFL1x_FYUVACxformAcEAlphaMul;
              break;
            case 10338:
            case 10346:
              result = FSI_D3D1xFL1x_FBatchYUVACxformAcEAlpha;
              break;
            case 10339:
            case 10347:
              result = FSI_D3D1xFL1x_FBatchYUVACxformAcEAlphaMul;
              break;
            case 10340:
            case 10348:
              result = FSI_D3D1xFL1x_FInstancedYUVACxformAcEAlpha;
              break;
            case 10341:
            case 10349:
              result = FSI_D3D1xFL1x_FInstancedYUVACxformAcEAlphaMul;
              break;
            default:
              return 0;
          }
          return result;
        }
        if ( shader > 21536 )
        {
          if ( shader > 24576 )
          {
            if ( shader > 24582 )
            {
              switch ( shader )
              {
                case 28672:
                  return 595;
                case 32768:
                  return 596;
                case 36864:
                  return 597;
              }
            }
            else
            {
              if ( shader == 24582 )
                return 593;
              v22 = shader - 24577;
              if ( !v22 )
                return 591;
              v23 = v22 - 1;
              if ( !v23 )
                return 590;
              v24 = v23 - 2;
              if ( !v24 )
                return 592;
              if ( v24 == 1 )
                return 594;
            }
          }
          else
          {
            if ( shader == 24576 )
              return 589;
            if ( shader > 21577 )
            {
              v19 = shader - 21632;
              if ( !v19 )
                return 577;
              v20 = v19 - 1;
              if ( !v20 )
                return 578;
              v21 = v20 - 7;
              if ( !v21 )
                return 579;
              if ( v21 == 1 )
                return 580;
            }
            else
            {
              if ( shader == 21577 )
                return 584;
              v16 = shader - 21537;
              if ( !v16 )
                return 586;
              v17 = v16 - 31;
              if ( !v17 )
                return 581;
              v18 = v17 - 1;
              if ( !v18 )
                return 582;
              if ( v18 == 7 )
                return 583;
            }
          }
        }
        else
        {
          if ( shader == 21536 )
            return 585;
          if ( shader > 20488 )
          {
            if ( shader > 20993 )
            {
              v13 = shader - 21000;
              if ( !v13 )
                return 573;
              v14 = v13 - 1;
              if ( !v14 )
                return 574;
              v15 = v14 - 519;
              if ( !v15 )
                return 587;
              if ( v15 == 1 )
                return 588;
            }
            else
            {
              if ( shader == 20993 )
                return 572;
              v10 = shader - 20489;
              if ( !v10 )
                return 570;
              v11 = v10 - 247;
              if ( !v11 )
                return 575;
              v12 = v11 - 1;
              if ( !v12 )
                return 576;
              if ( v12 == 255 )
                return 571;
            }
          }
          else
          {
            if ( shader == 20488 )
              return 569;
            if ( shader > 16385 )
            {
              v7 = shader - 18432;
              if ( !v7 )
                return 565;
              v8 = v7 - 1;
              if ( !v8 )
                return 566;
              v9 = v8 - 2047;
              if ( !v9 )
                return 567;
              if ( v9 == 1 )
                return 568;
            }
            else
            {
              if ( shader == 16385 )
                return 564;
              v4 = shader - 12289;
              if ( !v4 )
                return 560;
              v5 = v4 - 31;
              if ( !v5 )
                return 561;
              v6 = v5 - 1;
              if ( !v6 )
                return 562;
              if ( v6 == 4063 )
                return 563;
            }
          }
        }
      }
      return 0;
    }
    if ( shader > 4096 )
    {
      if ( shader > 5120 )
      {
        if ( shader > 6144 )
        {
          if ( shader > 0x2000 )
          {
            if ( shader > 10240 )
            {
              if ( shader > 12288 )
              {
                if ( shader > 21536 )
                {
                  if ( shader > 24576 )
                  {
                    if ( shader > 24582 )
                    {
                      switch ( shader )
                      {
                        case 28672:
                          return 328;
                        case 32768:
                          return 329;
                        case 36864:
                          return 330;
                      }
                    }
                    else
                    {
                      if ( shader == 24582 )
                        return 326;
                      v28 = shader - 24577;
                      if ( !v28 )
                        return 324;
                      v29 = v28 - 1;
                      if ( !v29 )
                        return 323;
                      v30 = v29 - 2;
                      if ( !v30 )
                        return 325;
                      if ( v30 == 1 )
                        return 327;
                    }
                  }
                  else if ( shader == 24576 )
                  {
                    return 322;
                  }
                }
                else if ( shader <= 0x4000 )
                {
                  v26 = shader - 12289;
                  if ( !v26 )
                    return 319;
                  v27 = v26 - 31;
                  if ( !v27 )
                    return 320;
                  if ( v27 == 1 )
                    return 321;
                }
                return 0;
              }
              if ( shader == 12288 )
              {
                return 318;
              }
              else
              {
                switch ( shader )
                {
                  case 10241:
                  case 10249:
                    result = FSI_D3D1xFL93_FYUVAMul;
                    break;
                  case 10242:
                  case 10250:
                    result = FSI_D3D1xFL93_FBatchYUVA;
                    break;
                  case 10243:
                  case 10251:
                    result = FSI_D3D1xFL93_FBatchYUVAMul;
                    break;
                  case 10248:
                    return 282;
                  case 10256:
                  case 10264:
                    result = FSI_D3D1xFL93_FYUVACxform;
                    break;
                  case 10257:
                  case 10265:
                    result = FSI_D3D1xFL93_FYUVACxformMul;
                    break;
                  case 10258:
                  case 10266:
                    result = FSI_D3D1xFL93_FBatchYUVACxform;
                    break;
                  case 10259:
                  case 10267:
                    result = FSI_D3D1xFL93_FBatchYUVACxformMul;
                    break;
                  case 10272:
                  case 10280:
                    result = FSI_D3D1xFL93_FYUVAEAlpha;
                    break;
                  case 10273:
                  case 10281:
                    result = FSI_D3D1xFL93_FYUVAEAlphaMul;
                    break;
                  case 10274:
                  case 10282:
                    result = FSI_D3D1xFL93_FBatchYUVAEAlpha;
                    break;
                  case 10275:
                  case 10283:
                    result = FSI_D3D1xFL93_FBatchYUVAEAlphaMul;
                    break;
                  case 10288:
                  case 10296:
                    result = FSI_D3D1xFL93_FYUVACxformEAlpha;
                    break;
                  case 10289:
                  case 10297:
                    result = FSI_D3D1xFL93_FYUVACxformEAlphaMul;
                    break;
                  case 10290:
                  case 10298:
                    result = FSI_D3D1xFL93_FBatchYUVACxformEAlpha;
                    break;
                  case 10291:
                  case 10299:
                    result = FSI_D3D1xFL93_FBatchYUVACxformEAlphaMul;
                    break;
                  case 10304:
                  case 10312:
                    result = FSI_D3D1xFL93_FYUVACxformAc;
                    break;
                  case 10305:
                  case 10313:
                    result = FSI_D3D1xFL93_FYUVACxformAcMul;
                    break;
                  case 10306:
                  case 10314:
                    result = FSI_D3D1xFL93_FBatchYUVACxformAc;
                    break;
                  case 10307:
                  case 10315:
                    result = FSI_D3D1xFL93_FBatchYUVACxformAcMul;
                    break;
                  case 10336:
                  case 10344:
                    result = FSI_D3D1xFL93_FYUVACxformAcEAlpha;
                    break;
                  case 10337:
                  case 10345:
                    result = FSI_D3D1xFL93_FYUVACxformAcEAlphaMul;
                    break;
                  case 10338:
                  case 10346:
                    result = FSI_D3D1xFL93_FBatchYUVACxformAcEAlpha;
                    break;
                  case 10339:
                  case 10347:
                    result = FSI_D3D1xFL93_FBatchYUVACxformAcEAlphaMul;
                    break;
                  default:
                    return 0;
                }
              }
            }
            else if ( shader == 10240 )
            {
              return 282;
            }
            else
            {
              switch ( shader )
              {
                case 8193:
                case 8201:
                  result = FSI_D3D1xFL93_FYUVMul;
                  break;
                case 8194:
                case 8202:
                  result = FSI_D3D1xFL93_FBatchYUV;
                  break;
                case 8195:
                case 8203:
                  result = FSI_D3D1xFL93_FBatchYUVMul;
                  break;
                case 8200:
                  return 270;
                case 8208:
                case 8216:
                  result = FSI_D3D1xFL93_FYUVCxform;
                  break;
                case 8209:
                case 8217:
                  result = FSI_D3D1xFL93_FYUVCxformMul;
                  break;
                case 8210:
                case 8218:
                  result = FSI_D3D1xFL93_FBatchYUVCxform;
                  break;
                case 8211:
                case 8219:
                  result = FSI_D3D1xFL93_FBatchYUVCxformMul;
                  break;
                case 8224:
                case 8232:
                  result = FSI_D3D1xFL93_FYUVEAlpha;
                  break;
                case 8225:
                case 8233:
                  result = FSI_D3D1xFL93_FYUVEAlphaMul;
                  break;
                case 8226:
                case 8234:
                  result = FSI_D3D1xFL93_FBatchYUVEAlpha;
                  break;
                case 8227:
                case 8235:
                  result = FSI_D3D1xFL93_FBatchYUVEAlphaMul;
                  break;
                case 8240:
                case 8248:
                  result = FSI_D3D1xFL93_FYUVCxformEAlpha;
                  break;
                case 8241:
                case 8249:
                  result = FSI_D3D1xFL93_FYUVCxformEAlphaMul;
                  break;
                case 8242:
                case 8250:
                  result = FSI_D3D1xFL93_FBatchYUVCxformEAlpha;
                  break;
                case 8243:
                case 8251:
                  result = FSI_D3D1xFL93_FBatchYUVCxformEAlphaMul;
                  break;
                case 8256:
                case 8264:
                  result = FSI_D3D1xFL93_FYUVCxformAc;
                  break;
                case 8257:
                case 8265:
                  result = FSI_D3D1xFL93_FYUVCxformAcMul;
                  break;
                case 8258:
                case 8266:
                  result = FSI_D3D1xFL93_FBatchYUVCxformAc;
                  break;
                case 8259:
                case 8267:
                  result = FSI_D3D1xFL93_FBatchYUVCxformAcMul;
                  break;
                case 8288:
                case 8296:
                  result = FSI_D3D1xFL93_FYUVCxformAcEAlpha;
                  break;
                case 8289:
                case 8297:
                  result = FSI_D3D1xFL93_FYUVCxformAcEAlphaMul;
                  break;
                case 8290:
                case 8298:
                  result = FSI_D3D1xFL93_FBatchYUVCxformAcEAlpha;
                  break;
                case 8291:
                case 8299:
                  result = FSI_D3D1xFL93_FBatchYUVCxformAcEAlphaMul;
                  break;
                default:
                  return 0;
              }
            }
          }
          else if ( shader == 0x2000 )
          {
            return 270;
          }
          else
          {
            switch ( shader )
            {
              case 6145:
              case 6153:
$LN1043:
                result = FSI_D3D1xFL93_FTexTGMul;
                break;
              case 6146:
              case 6154:
$LN1042_0:
                result = FSI_D3D1xFL93_FBatchTexTG;
                break;
              case 6147:
              case 6155:
$LN1041:
                result = FSI_D3D1xFL93_FBatchTexTGMul;
                break;
              case 6152:
                return 166;
              case 6160:
              case 6168:
$LN1032_0:
                result = FSI_D3D1xFL93_FTexTGCxform;
                break;
              case 6161:
              case 6169:
$LN1031:
                result = FSI_D3D1xFL93_FTexTGCxformMul;
                break;
              case 6162:
              case 6170:
$LN1030_0:
                result = FSI_D3D1xFL93_FBatchTexTGCxform;
                break;
              case 6163:
              case 6171:
$LN1029:
                result = FSI_D3D1xFL93_FBatchTexTGCxformMul;
                break;
              default:
                return 0;
            }
          }
        }
        else if ( shader == 6144 )
        {
          return 166;
        }
        else
        {
          switch ( shader )
          {
            case 5121:
            case 5129:
              result = FSI_D3D1xFL93_FTextMul;
              break;
            case 5122:
            case 5130:
              result = FSI_D3D1xFL93_FBatchText;
              break;
            case 5123:
            case 5131:
              result = FSI_D3D1xFL93_FBatchTextMul;
              break;
            case 5128:
              return 264;
            default:
              return 0;
          }
        }
      }
      else if ( shader == 5120 )
      {
        return 264;
      }
      else
      {
        switch ( shader )
        {
          case 4097:
          case 4105:
            result = FSI_D3D1xFL93_FSolidMul;
            break;
          case 4098:
          case 4106:
            result = FSI_D3D1xFL93_FBatchSolid;
            break;
          case 4099:
          case 4107:
            result = FSI_D3D1xFL93_FBatchSolidMul;
            break;
          case 4104:
            return 262;
          default:
            return 0;
        }
      }
    }
    else
    {
      if ( shader == 4096 )
        return 262;
      result = FSI_D3D1xFL93_FBatchTexTGVertexCxformEAlphaMul;
      if ( shader > 257 )
      {
        switch ( shader )
        {
          case 258:
          case 266:
            result = FSI_D3D1xFL93_FTexTGTexTGMul;
            break;
          case 259:
          case 267:
            result = FSI_D3D1xFL93_FBatchTexTGTexTG;
            break;
          case 260:
          case 268:
            result = FSI_D3D1xFL93_FBatchTexTGTexTGMul;
            break;
          case 265:
            return 190;
          case 273:
          case 281:
            result = FSI_D3D1xFL93_FTexTGTexTGCxform;
            break;
          case 274:
          case 282:
            result = FSI_D3D1xFL93_FTexTGTexTGCxformMul;
            break;
          case 275:
          case 283:
            result = FSI_D3D1xFL93_FBatchTexTGTexTGCxform;
            break;
          case 276:
          case 284:
            result = FSI_D3D1xFL93_FBatchTexTGTexTGCxformMul;
            break;
          case 289:
          case 297:
            result = FSI_D3D1xFL93_FTexTGTexTGEAlpha;
            break;
          case 290:
          case 298:
            result = FSI_D3D1xFL93_FTexTGTexTGEAlphaMul;
            break;
          case 291:
          case 299:
            result = FSI_D3D1xFL93_FBatchTexTGTexTGEAlpha;
            break;
          case 292:
          case 300:
            result = FSI_D3D1xFL93_FBatchTexTGTexTGEAlphaMul;
            break;
          case 305:
          case 313:
            result = FSI_D3D1xFL93_FTexTGTexTGCxformEAlpha;
            break;
          case 306:
          case 314:
            result = FSI_D3D1xFL93_FTexTGTexTGCxformEAlphaMul;
            break;
          case 307:
          case 315:
            result = FSI_D3D1xFL93_FBatchTexTGTexTGCxformEAlpha;
            break;
          case 308:
          case 316:
            result = FSI_D3D1xFL93_FBatchTexTGTexTGCxformEAlphaMul;
            break;
          case 321:
          case 329:
            result = FSI_D3D1xFL93_FTexTGTexTGCxformAc;
            break;
          case 322:
          case 330:
            result = FSI_D3D1xFL93_FTexTGTexTGCxformAcMul;
            break;
          case 323:
          case 331:
            result = FSI_D3D1xFL93_FBatchTexTGTexTGCxformAc;
            break;
          case 324:
          case 332:
            result = FSI_D3D1xFL93_FBatchTexTGTexTGCxformAcMul;
            break;
          case 353:
          case 361:
            result = FSI_D3D1xFL93_FTexTGTexTGCxformAcEAlpha;
            break;
          case 354:
          case 362:
            result = FSI_D3D1xFL93_FTexTGTexTGCxformAcEAlphaMul;
            break;
          case 355:
          case 363:
            result = FSI_D3D1xFL93_FBatchTexTGTexTGCxformAcEAlpha;
            break;
          case 356:
          case 364:
            result = FSI_D3D1xFL93_FBatchTexTGTexTGCxformAcEAlphaMul;
            break;
          case 513:
          case 521:
            result = FSI_D3D1xFL93_FTexTGVertex;
            break;
          case 514:
          case 522:
            result = FSI_D3D1xFL93_FTexTGVertexMul;
            break;
          case 515:
          case 523:
            result = FSI_D3D1xFL93_FBatchTexTGVertex;
            break;
          case 516:
          case 524:
            result = FSI_D3D1xFL93_FBatchTexTGVertexMul;
            break;
          case 529:
          case 537:
            result = FSI_D3D1xFL93_FTexTGVertexCxform;
            break;
          case 530:
          case 538:
            result = FSI_D3D1xFL93_FTexTGVertexCxformMul;
            break;
          case 531:
          case 539:
            result = FSI_D3D1xFL93_FBatchTexTGVertexCxform;
            break;
          case 532:
          case 540:
            result = FSI_D3D1xFL93_FBatchTexTGVertexCxformMul;
            break;
          case 545:
          case 553:
            result = FSI_D3D1xFL93_FTexTGVertexEAlpha;
            break;
          case 546:
          case 554:
            result = FSI_D3D1xFL93_FTexTGVertexEAlphaMul;
            break;
          case 547:
          case 555:
            result = FSI_D3D1xFL93_FBatchTexTGVertexEAlpha;
            break;
          case 548:
          case 556:
            result = FSI_D3D1xFL93_FBatchTexTGVertexEAlphaMul;
            break;
          case 561:
          case 569:
            result = FSI_D3D1xFL93_FTexTGVertexCxformEAlpha;
            break;
          case 562:
          case 570:
            result = FSI_D3D1xFL93_FTexTGVertexCxformEAlphaMul;
            break;
          case 563:
          case 571:
            result = FSI_D3D1xFL93_FBatchTexTGVertexCxformEAlpha;
            break;
          case 564:
          case 572:
            return result;
          case 577:
          case 585:
            result = FSI_D3D1xFL93_FTexTGVertexCxformAc;
            break;
          case 578:
          case 586:
            result = FSI_D3D1xFL93_FTexTGVertexCxformAcMul;
            break;
          case 579:
          case 587:
            result = FSI_D3D1xFL93_FBatchTexTGVertexCxformAc;
            break;
          case 580:
          case 588:
            result = FSI_D3D1xFL93_FBatchTexTGVertexCxformAcMul;
            break;
          case 609:
          case 617:
            result = FSI_D3D1xFL93_FTexTGVertexCxformAcEAlpha;
            break;
          case 610:
          case 618:
            result = FSI_D3D1xFL93_FTexTGVertexCxformAcEAlphaMul;
            break;
          case 611:
          case 619:
            result = FSI_D3D1xFL93_FBatchTexTGVertexCxformAcEAlpha;
            break;
          case 612:
          case 620:
            result = FSI_D3D1xFL93_FBatchTexTGVertexCxformAcEAlphaMul;
            break;
          default:
            return 0;
        }
      }
      else
      {
        if ( shader == 257 )
          return 190;
        v25 = shader - 1;
        result = FSI_D3D1xFL93_FBatchVertexCxformAcEAlphaMul;
        if ( v25 > 0xED )
          return 0;
        switch ( v25 )
        {
          case 0u:
          case 8u:
            return 166;
          case 1u:
          case 9u:
            goto $LN1043;
          case 2u:
          case 0xAu:
            goto $LN1042_0;
          case 3u:
          case 0xBu:
            goto $LN1041;
          case 4u:
          case 5u:
          case 6u:
          case 7u:
          case 0xCu:
          case 0xDu:
          case 0xEu:
          case 0xFu:
          case 0x14u:
          case 0x15u:
          case 0x16u:
          case 0x17u:
          case 0x1Cu:
          case 0x1Du:
          case 0x1Eu:
          case 0x1Fu:
          case 0x24u:
          case 0x25u:
          case 0x26u:
          case 0x27u:
          case 0x2Cu:
          case 0x2Du:
          case 0x2Eu:
          case 0x2Fu:
          case 0x34u:
          case 0x35u:
          case 0x36u:
          case 0x37u:
          case 0x3Cu:
          case 0x3Du:
          case 0x3Eu:
          case 0x3Fu:
          case 0x44u:
          case 0x45u:
          case 0x46u:
          case 0x47u:
          case 0x4Cu:
          case 0x4Du:
          case 0x4Eu:
          case 0x4Fu:
          case 0x50u:
          case 0x51u:
          case 0x52u:
          case 0x53u:
          case 0x54u:
          case 0x55u:
          case 0x56u:
          case 0x57u:
          case 0x58u:
          case 0x59u:
          case 0x5Au:
          case 0x5Bu:
          case 0x5Cu:
          case 0x5Du:
          case 0x5Eu:
          case 0x5Fu:
          case 0x64u:
          case 0x65u:
          case 0x66u:
          case 0x67u:
          case 0x6Cu:
          case 0x6Du:
          case 0x6Eu:
          case 0x6Fu:
          case 0x70u:
          case 0x71u:
          case 0x72u:
          case 0x73u:
          case 0x74u:
          case 0x75u:
          case 0x76u:
          case 0x77u:
          case 0x78u:
          case 0x79u:
          case 0x7Au:
          case 0x7Bu:
          case 0x7Cu:
          case 0x7Du:
          case 0x7Eu:
          case 0x7Fu:
          case 0x84u:
          case 0x85u:
          case 0x86u:
          case 0x87u:
          case 0x8Cu:
          case 0x8Du:
          case 0x8Eu:
          case 0x8Fu:
          case 0x94u:
          case 0x95u:
          case 0x96u:
          case 0x97u:
          case 0x9Cu:
          case 0x9Du:
          case 0x9Eu:
          case 0x9Fu:
          case 0xA4u:
          case 0xA5u:
          case 0xA6u:
          case 0xA7u:
          case 0xACu:
          case 0xADu:
          case 0xAEu:
          case 0xAFu:
          case 0xB4u:
          case 0xB5u:
          case 0xB6u:
          case 0xB7u:
          case 0xBCu:
          case 0xBDu:
          case 0xBEu:
          case 0xBFu:
          case 0xC4u:
          case 0xC5u:
          case 0xC6u:
          case 0xC7u:
          case 0xCCu:
          case 0xCDu:
          case 0xCEu:
          case 0xCFu:
          case 0xD0u:
          case 0xD1u:
          case 0xD2u:
          case 0xD3u:
          case 0xD4u:
          case 0xD5u:
          case 0xD6u:
          case 0xD7u:
          case 0xD8u:
          case 0xD9u:
          case 0xDAu:
          case 0xDBu:
          case 0xDCu:
          case 0xDDu:
          case 0xDEu:
          case 0xDFu:
          case 0xE4u:
          case 0xE5u:
          case 0xE6u:
          case 0xE7u:
          case 0xECu:
          case 0xEDu:
            return 0;
          case 0x10u:
          case 0x18u:
            goto $LN1032_0;
          case 0x11u:
          case 0x19u:
            goto $LN1031;
          case 0x12u:
          case 0x1Au:
            goto $LN1030_0;
          case 0x13u:
          case 0x1Bu:
            goto $LN1029;
          case 0x20u:
          case 0x28u:
            result = FSI_D3D1xFL93_FTexTGEAlpha;
            break;
          case 0x21u:
          case 0x29u:
            result = FSI_D3D1xFL93_FTexTGEAlphaMul;
            break;
          case 0x22u:
          case 0x2Au:
            result = FSI_D3D1xFL93_FBatchTexTGEAlpha;
            break;
          case 0x23u:
          case 0x2Bu:
            result = FSI_D3D1xFL93_FBatchTexTGEAlphaMul;
            break;
          case 0x30u:
          case 0x38u:
            result = FSI_D3D1xFL93_FTexTGCxformEAlpha;
            break;
          case 0x31u:
          case 0x39u:
            result = FSI_D3D1xFL93_FTexTGCxformEAlphaMul;
            break;
          case 0x32u:
          case 0x3Au:
            result = FSI_D3D1xFL93_FBatchTexTGCxformEAlpha;
            break;
          case 0x33u:
          case 0x3Bu:
            result = FSI_D3D1xFL93_FBatchTexTGCxformEAlphaMul;
            break;
          case 0x40u:
          case 0x48u:
            result = FSI_D3D1xFL93_FTexTGCxformAc;
            break;
          case 0x41u:
          case 0x49u:
            result = FSI_D3D1xFL93_FTexTGCxformAcMul;
            break;
          case 0x42u:
          case 0x4Au:
            result = FSI_D3D1xFL93_FBatchTexTGCxformAc;
            break;
          case 0x43u:
          case 0x4Bu:
            result = FSI_D3D1xFL93_FBatchTexTGCxformAcMul;
            break;
          case 0x60u:
          case 0x68u:
            result = FSI_D3D1xFL93_FTexTGCxformAcEAlpha;
            break;
          case 0x61u:
          case 0x69u:
            result = FSI_D3D1xFL93_FTexTGCxformAcEAlphaMul;
            break;
          case 0x62u:
          case 0x6Au:
            result = FSI_D3D1xFL93_FBatchTexTGCxformAcEAlpha;
            break;
          case 0x63u:
          case 0x6Bu:
            result = FSI_D3D1xFL93_FBatchTexTGCxformAcEAlphaMul;
            break;
          case 0x80u:
          case 0x88u:
            result = FSI_D3D1xFL93_FVertex;
            break;
          case 0x81u:
          case 0x89u:
            result = FSI_D3D1xFL93_FVertexMul;
            break;
          case 0x82u:
          case 0x8Au:
            result = FSI_D3D1xFL93_FBatchVertex;
            break;
          case 0x83u:
          case 0x8Bu:
            result = FSI_D3D1xFL93_FBatchVertexMul;
            break;
          case 0x90u:
          case 0x98u:
            result = FSI_D3D1xFL93_FVertexCxform;
            break;
          case 0x91u:
          case 0x99u:
            result = FSI_D3D1xFL93_FVertexCxformMul;
            break;
          case 0x92u:
          case 0x9Au:
            result = FSI_D3D1xFL93_FBatchVertexCxform;
            break;
          case 0x93u:
          case 0x9Bu:
            result = FSI_D3D1xFL93_FBatchVertexCxformMul;
            break;
          case 0xA0u:
          case 0xA8u:
            result = FSI_D3D1xFL93_FVertexEAlpha;
            break;
          case 0xA1u:
          case 0xA9u:
            result = FSI_D3D1xFL93_FVertexEAlphaMul;
            break;
          case 0xA2u:
          case 0xAAu:
            result = FSI_D3D1xFL93_FBatchVertexEAlpha;
            break;
          case 0xA3u:
          case 0xABu:
            result = FSI_D3D1xFL93_FBatchVertexEAlphaMul;
            break;
          case 0xB0u:
          case 0xB8u:
            result = FSI_D3D1xFL93_FVertexCxformEAlpha;
            break;
          case 0xB1u:
          case 0xB9u:
            result = FSI_D3D1xFL93_FVertexCxformEAlphaMul;
            break;
          case 0xB2u:
          case 0xBAu:
            result = FSI_D3D1xFL93_FBatchVertexCxformEAlpha;
            break;
          case 0xB3u:
          case 0xBBu:
            result = FSI_D3D1xFL93_FBatchVertexCxformEAlphaMul;
            break;
          case 0xC0u:
          case 0xC8u:
            result = FSI_D3D1xFL93_FVertexCxformAc;
            break;
          case 0xC1u:
          case 0xC9u:
            result = FSI_D3D1xFL93_FVertexCxformAcMul;
            break;
          case 0xC2u:
          case 0xCAu:
            result = FSI_D3D1xFL93_FBatchVertexCxformAc;
            break;
          case 0xC3u:
          case 0xCBu:
            result = FSI_D3D1xFL93_FBatchVertexCxformAcMul;
            break;
          case 0xE0u:
          case 0xE8u:
            result = FSI_D3D1xFL93_FVertexCxformAcEAlpha;
            break;
          case 0xE1u:
          case 0xE9u:
            result = FSI_D3D1xFL93_FVertexCxformAcEAlphaMul;
            break;
          case 0xE2u:
          case 0xEAu:
            result = FSI_D3D1xFL93_FBatchVertexCxformAcEAlpha;
            break;
          case 0xE3u:
          case 0xEBu:
            return result;
        }
      }
    }
  }
  else if ( shader > 4096 )
  {
    if ( shader > 5120 )
    {
      if ( shader > 6144 )
      {
        if ( shader > 0x2000 )
        {
          if ( shader > 10240 )
          {
            if ( shader > 12288 )
            {
              if ( shader > 21536 )
              {
                if ( shader > 24576 )
                {
                  if ( shader > 24582 )
                  {
                    switch ( shader )
                    {
                      case 28672:
                        return 163;
                      case 32768:
                        return 164;
                      case 36864:
                        return 165;
                    }
                  }
                  else
                  {
                    if ( shader == 24582 )
                      return 161;
                    v33 = shader - 24577;
                    if ( !v33 )
                      return 159;
                    v34 = v33 - 1;
                    if ( !v34 )
                      return 158;
                    v35 = v34 - 2;
                    if ( !v35 )
                      return 160;
                    if ( v35 == 1 )
                      return 162;
                  }
                }
                else if ( shader == 24576 )
                {
                  return 157;
                }
              }
              else if ( shader <= 0x4000 )
              {
                v31 = shader - 12289;
                if ( !v31 )
                  return 154;
                v32 = v31 - 31;
                if ( !v32 )
                  return 155;
                if ( v32 == 1 )
                  return 156;
              }
              return 0;
            }
            if ( shader == 12288 )
            {
              return 153;
            }
            else
            {
              switch ( shader )
              {
                case 10241:
                case 10249:
                  result = FSI_D3D1xFL91_FYUVAMul;
                  break;
                case 10242:
                case 10250:
                  result = FSI_D3D1xFL91_FBatchYUVA;
                  break;
                case 10243:
                case 10251:
                  result = FSI_D3D1xFL91_FBatchYUVAMul;
                  break;
                case 10248:
                  return 117;
                case 10256:
                case 10264:
                  result = FSI_D3D1xFL91_FYUVACxform;
                  break;
                case 10257:
                case 10265:
                  result = FSI_D3D1xFL91_FYUVACxformMul;
                  break;
                case 10258:
                case 10266:
                  result = FSI_D3D1xFL91_FBatchYUVACxform;
                  break;
                case 10259:
                case 10267:
                  result = FSI_D3D1xFL91_FBatchYUVACxformMul;
                  break;
                case 10272:
                case 10280:
                  result = FSI_D3D1xFL91_FYUVAEAlpha;
                  break;
                case 10273:
                case 10281:
                  result = FSI_D3D1xFL91_FYUVAEAlphaMul;
                  break;
                case 10274:
                case 10282:
                  result = FSI_D3D1xFL91_FBatchYUVAEAlpha;
                  break;
                case 10275:
                case 10283:
                  result = FSI_D3D1xFL91_FBatchYUVAEAlphaMul;
                  break;
                case 10288:
                case 10296:
                  result = FSI_D3D1xFL91_FYUVACxformEAlpha;
                  break;
                case 10289:
                case 10297:
                  result = FSI_D3D1xFL91_FYUVACxformEAlphaMul;
                  break;
                case 10290:
                case 10298:
                  result = FSI_D3D1xFL91_FBatchYUVACxformEAlpha;
                  break;
                case 10291:
                case 10299:
                  result = FSI_D3D1xFL91_FBatchYUVACxformEAlphaMul;
                  break;
                case 10304:
                case 10312:
                  result = FSI_D3D1xFL91_FYUVACxformAc;
                  break;
                case 10305:
                case 10313:
                  result = FSI_D3D1xFL91_FYUVACxformAcMul;
                  break;
                case 10306:
                case 10314:
                  result = FSI_D3D1xFL91_FBatchYUVACxformAc;
                  break;
                case 10307:
                case 10315:
                  result = FSI_D3D1xFL91_FBatchYUVACxformAcMul;
                  break;
                case 10336:
                case 10344:
                  result = FSI_D3D1xFL91_FYUVACxformAcEAlpha;
                  break;
                case 10337:
                case 10345:
                  result = FSI_D3D1xFL91_FYUVACxformAcEAlphaMul;
                  break;
                case 10338:
                case 10346:
                  result = FSI_D3D1xFL91_FBatchYUVACxformAcEAlpha;
                  break;
                case 10339:
                case 10347:
                  result = FSI_D3D1xFL91_FBatchYUVACxformAcEAlphaMul;
                  break;
                default:
                  return 0;
              }
            }
          }
          else if ( shader == 10240 )
          {
            return 117;
          }
          else
          {
            switch ( shader )
            {
              case 8193:
              case 8201:
                result = FSI_D3D1xFL91_FYUVMul;
                break;
              case 8194:
              case 8202:
                result = FSI_D3D1xFL91_FBatchYUV;
                break;
              case 8195:
              case 8203:
                result = FSI_D3D1xFL91_FBatchYUVMul;
                break;
              case 8200:
                return 105;
              case 8208:
              case 8216:
                result = FSI_D3D1xFL91_FYUVCxform;
                break;
              case 8209:
              case 8217:
                result = FSI_D3D1xFL91_FYUVCxformMul;
                break;
              case 8210:
              case 8218:
                result = FSI_D3D1xFL91_FBatchYUVCxform;
                break;
              case 8211:
              case 8219:
                result = FSI_D3D1xFL91_FBatchYUVCxformMul;
                break;
              case 8224:
              case 8232:
                result = FSI_D3D1xFL91_FYUVEAlpha;
                break;
              case 8225:
              case 8233:
                result = FSI_D3D1xFL91_FYUVEAlphaMul;
                break;
              case 8226:
              case 8234:
                result = FSI_D3D1xFL91_FBatchYUVEAlpha;
                break;
              case 8227:
              case 8235:
                result = FSI_D3D1xFL91_FBatchYUVEAlphaMul;
                break;
              case 8240:
              case 8248:
                result = FSI_D3D1xFL91_FYUVCxformEAlpha;
                break;
              case 8241:
              case 8249:
                result = FSI_D3D1xFL91_FYUVCxformEAlphaMul;
                break;
              case 8242:
              case 8250:
                result = FSI_D3D1xFL91_FBatchYUVCxformEAlpha;
                break;
              case 8243:
              case 8251:
                result = FSI_D3D1xFL91_FBatchYUVCxformEAlphaMul;
                break;
              case 8256:
              case 8264:
                result = FSI_D3D1xFL91_FYUVCxformAc;
                break;
              case 8257:
              case 8265:
                result = FSI_D3D1xFL91_FYUVCxformAcMul;
                break;
              case 8258:
              case 8266:
                result = FSI_D3D1xFL91_FBatchYUVCxformAc;
                break;
              case 8259:
              case 8267:
                result = FSI_D3D1xFL91_FBatchYUVCxformAcMul;
                break;
              case 8288:
              case 8296:
                result = FSI_D3D1xFL91_FYUVCxformAcEAlpha;
                break;
              case 8289:
              case 8297:
                result = FSI_D3D1xFL91_FYUVCxformAcEAlphaMul;
                break;
              case 8290:
              case 8298:
                result = FSI_D3D1xFL91_FBatchYUVCxformAcEAlpha;
                break;
              case 8291:
              case 8299:
                result = FSI_D3D1xFL91_FBatchYUVCxformAcEAlphaMul;
                break;
              default:
                return 0;
            }
          }
        }
        else if ( shader == 0x2000 )
        {
          return 105;
        }
        else
        {
          switch ( shader )
          {
            case 6145:
            case 6153:
$LN1566:
              result = FSI_D3D1xFL91_FTexTGMul;
              break;
            case 6146:
            case 6154:
$LN1565_0:
              result = FSI_D3D1xFL91_FBatchTexTG;
              break;
            case 6147:
            case 6155:
$LN1564:
              result = FSI_D3D1xFL91_FBatchTexTGMul;
              break;
            case 6152:
              return 1;
            case 6160:
            case 6168:
$LN1555_0:
              result = FSI_D3D1xFL91_FTexTGCxform;
              break;
            case 6161:
            case 6169:
$LN1554:
              result = FSI_D3D1xFL91_FTexTGCxformMul;
              break;
            case 6162:
            case 6170:
$LN1553_0:
              result = FSI_D3D1xFL91_FBatchTexTGCxform;
              break;
            case 6163:
            case 6171:
$LN1552:
              result = FSI_D3D1xFL91_FBatchTexTGCxformMul;
              break;
            default:
              return 0;
          }
        }
      }
      else if ( shader == 6144 )
      {
        return 1;
      }
      else
      {
        switch ( shader )
        {
          case 5121:
          case 5129:
            result = FSI_D3D1xFL91_FTextMul;
            break;
          case 5122:
          case 5130:
            result = FSI_D3D1xFL91_FBatchText;
            break;
          case 5123:
          case 5131:
            result = FSI_D3D1xFL91_FBatchTextMul;
            break;
          case 5128:
            return 99;
          default:
            return 0;
        }
      }
    }
    else if ( shader == 5120 )
    {
      return 99;
    }
    else
    {
      switch ( shader )
      {
        case 4097:
        case 4105:
          result = FSI_D3D1xFL91_FSolidMul;
          break;
        case 4098:
        case 4106:
          result = FSI_D3D1xFL91_FBatchSolid;
          break;
        case 4099:
        case 4107:
          result = FSI_D3D1xFL91_FBatchSolidMul;
          break;
        case 4104:
          return 97;
        default:
          return 0;
      }
    }
  }
  else if ( shader == 4096 )
  {
    return 97;
  }
  else if ( shader > 257 )
  {
    switch ( shader )
    {
      case 258:
      case 266:
        result = FSI_D3D1xFL91_FTexTGTexTGMul;
        break;
      case 259:
      case 267:
        result = FSI_D3D1xFL91_FBatchTexTGTexTG;
        break;
      case 260:
      case 268:
        result = FSI_D3D1xFL91_FBatchTexTGTexTGMul;
        break;
      case 265:
        return 25;
      case 273:
      case 281:
        result = FSI_D3D1xFL91_FTexTGTexTGCxform;
        break;
      case 274:
      case 282:
        result = FSI_D3D1xFL91_FTexTGTexTGCxformMul;
        break;
      case 275:
      case 283:
        result = FSI_D3D1xFL91_FBatchTexTGTexTGCxform;
        break;
      case 276:
      case 284:
        result = FSI_D3D1xFL91_FBatchTexTGTexTGCxformMul;
        break;
      case 289:
      case 297:
        result = FSI_D3D1xFL91_FTexTGTexTGEAlpha;
        break;
      case 290:
      case 298:
        result = FSI_D3D1xFL91_FTexTGTexTGEAlphaMul;
        break;
      case 291:
      case 299:
        result = FSI_D3D1xFL91_FBatchTexTGTexTGEAlpha;
        break;
      case 292:
      case 300:
        result = FSI_D3D1xFL91_FBatchTexTGTexTGEAlphaMul;
        break;
      case 305:
      case 313:
        result = FSI_D3D1xFL91_FTexTGTexTGCxformEAlpha;
        break;
      case 306:
      case 314:
        result = FSI_D3D1xFL91_FTexTGTexTGCxformEAlphaMul;
        break;
      case 307:
      case 315:
        result = FSI_D3D1xFL91_FBatchTexTGTexTGCxformEAlpha;
        break;
      case 308:
      case 316:
        result = FSI_D3D1xFL91_FBatchTexTGTexTGCxformEAlphaMul;
        break;
      case 321:
      case 329:
        result = FSI_D3D1xFL91_FTexTGTexTGCxformAc;
        break;
      case 322:
      case 330:
        result = FSI_D3D1xFL91_FTexTGTexTGCxformAcMul;
        break;
      case 323:
      case 331:
        result = FSI_D3D1xFL91_FBatchTexTGTexTGCxformAc;
        break;
      case 324:
      case 332:
        result = FSI_D3D1xFL91_FBatchTexTGTexTGCxformAcMul;
        break;
      case 353:
      case 361:
        result = FSI_D3D1xFL91_FTexTGTexTGCxformAcEAlpha;
        break;
      case 354:
      case 362:
        result = FSI_D3D1xFL91_FTexTGTexTGCxformAcEAlphaMul;
        break;
      case 355:
      case 363:
        result = FSI_D3D1xFL91_FBatchTexTGTexTGCxformAcEAlpha;
        break;
      case 356:
      case 364:
        result = FSI_D3D1xFL91_FBatchTexTGTexTGCxformAcEAlphaMul;
        break;
      case 513:
      case 521:
        result = FSI_D3D1xFL91_FTexTGVertex;
        break;
      case 514:
      case 522:
        result = FSI_D3D1xFL91_FTexTGVertexMul;
        break;
      case 515:
      case 523:
        result = FSI_D3D1xFL91_FBatchTexTGVertex;
        break;
      case 516:
      case 524:
        result = FSI_D3D1xFL91_FBatchTexTGVertexMul;
        break;
      case 529:
      case 537:
        result = FSI_D3D1xFL91_FTexTGVertexCxform;
        break;
      case 530:
      case 538:
        result = FSI_D3D1xFL91_FTexTGVertexCxformMul;
        break;
      case 531:
      case 539:
        result = FSI_D3D1xFL91_FBatchTexTGVertexCxform;
        break;
      case 532:
      case 540:
        result = FSI_D3D1xFL91_FBatchTexTGVertexCxformMul;
        break;
      case 545:
      case 553:
        result = FSI_D3D1xFL91_FTexTGVertexEAlpha;
        break;
      case 546:
      case 554:
        result = FSI_D3D1xFL91_FTexTGVertexEAlphaMul;
        break;
      case 547:
      case 555:
        result = FSI_D3D1xFL91_FBatchTexTGVertexEAlpha;
        break;
      case 548:
      case 556:
        result = FSI_D3D1xFL91_FBatchTexTGVertexEAlphaMul;
        break;
      case 561:
      case 569:
        result = FSI_D3D1xFL91_FTexTGVertexCxformEAlpha;
        break;
      case 562:
      case 570:
        result = FSI_D3D1xFL91_FTexTGVertexCxformEAlphaMul;
        break;
      case 563:
      case 571:
        result = FSI_D3D1xFL91_FBatchTexTGVertexCxformEAlpha;
        break;
      case 564:
      case 572:
        result = FSI_D3D1xFL91_FBatchTexTGVertexCxformEAlphaMul;
        break;
      case 577:
      case 585:
        result = FSI_D3D1xFL91_FTexTGVertexCxformAc;
        break;
      case 578:
      case 586:
        result = FSI_D3D1xFL91_FTexTGVertexCxformAcMul;
        break;
      case 579:
      case 587:
        result = FSI_D3D1xFL91_FBatchTexTGVertexCxformAc;
        break;
      case 580:
      case 588:
        result = FSI_D3D1xFL91_FBatchTexTGVertexCxformAcMul;
        break;
      case 609:
      case 617:
        result = FSI_D3D1xFL91_FTexTGVertexCxformAcEAlpha;
        break;
      case 610:
      case 618:
        result = FSI_D3D1xFL91_FTexTGVertexCxformAcEAlphaMul;
        break;
      case 611:
      case 619:
        result = FSI_D3D1xFL91_FBatchTexTGVertexCxformAcEAlpha;
        break;
      case 612:
      case 620:
        result = FSI_D3D1xFL91_FBatchTexTGVertexCxformAcEAlphaMul;
        break;
      default:
        return 0;
    }
  }
  else if ( shader == 257 )
  {
    return 25;
  }
  else
  {
    switch ( shader )
    {
      case 1:
      case 9:
        return 1;
      case 2:
      case 10:
        goto $LN1566;
      case 3:
      case 11:
        goto $LN1565_0;
      case 4:
      case 12:
        goto $LN1564;
      case 17:
      case 25:
        goto $LN1555_0;
      case 18:
      case 26:
        goto $LN1554;
      case 19:
      case 27:
        goto $LN1553_0;
      case 20:
      case 28:
        goto $LN1552;
      case 33:
      case 41:
        result = FSI_D3D1xFL91_FTexTGEAlpha;
        break;
      case 34:
      case 42:
        result = FSI_D3D1xFL91_FTexTGEAlphaMul;
        break;
      case 35:
      case 43:
        result = FSI_D3D1xFL91_FBatchTexTGEAlpha;
        break;
      case 36:
      case 44:
        result = FSI_D3D1xFL91_FBatchTexTGEAlphaMul;
        break;
      case 49:
      case 57:
        result = FSI_D3D1xFL91_FTexTGCxformEAlpha;
        break;
      case 50:
      case 58:
        result = FSI_D3D1xFL91_FTexTGCxformEAlphaMul;
        break;
      case 51:
      case 59:
        result = FSI_D3D1xFL91_FBatchTexTGCxformEAlpha;
        break;
      case 52:
      case 60:
        result = FSI_D3D1xFL91_FBatchTexTGCxformEAlphaMul;
        break;
      case 65:
      case 73:
        result = FSI_D3D1xFL91_FTexTGCxformAc;
        break;
      case 66:
      case 74:
        result = FSI_D3D1xFL91_FTexTGCxformAcMul;
        break;
      case 67:
      case 75:
        result = FSI_D3D1xFL91_FBatchTexTGCxformAc;
        break;
      case 68:
      case 76:
        result = FSI_D3D1xFL91_FBatchTexTGCxformAcMul;
        break;
      case 97:
      case 105:
        result = FSI_D3D1xFL91_FTexTGCxformAcEAlpha;
        break;
      case 98:
      case 106:
        result = FSI_D3D1xFL91_FTexTGCxformAcEAlphaMul;
        break;
      case 99:
      case 107:
        result = FSI_D3D1xFL91_FBatchTexTGCxformAcEAlpha;
        break;
      case 100:
      case 108:
        result = FSI_D3D1xFL91_FBatchTexTGCxformAcEAlphaMul;
        break;
      case 129:
      case 137:
        result = FSI_D3D1xFL91_FVertex;
        break;
      case 130:
      case 138:
        result = FSI_D3D1xFL91_FVertexMul;
        break;
      case 131:
      case 139:
        result = FSI_D3D1xFL91_FBatchVertex;
        break;
      case 132:
      case 140:
        result = FSI_D3D1xFL91_FBatchVertexMul;
        break;
      case 145:
      case 153:
        result = FSI_D3D1xFL91_FVertexCxform;
        break;
      case 146:
      case 154:
        result = FSI_D3D1xFL91_FVertexCxformMul;
        break;
      case 147:
      case 155:
        result = FSI_D3D1xFL91_FBatchVertexCxform;
        break;
      case 148:
      case 156:
        result = FSI_D3D1xFL91_FBatchVertexCxformMul;
        break;
      case 161:
      case 169:
        result = FSI_D3D1xFL91_FVertexEAlpha;
        break;
      case 162:
      case 170:
        result = FSI_D3D1xFL91_FVertexEAlphaMul;
        break;
      case 163:
      case 171:
        result = FSI_D3D1xFL91_FBatchVertexEAlpha;
        break;
      case 164:
      case 172:
        result = FSI_D3D1xFL91_FBatchVertexEAlphaMul;
        break;
      case 177:
      case 185:
        result = FSI_D3D1xFL91_FVertexCxformEAlpha;
        break;
      case 178:
      case 186:
        result = FSI_D3D1xFL91_FVertexCxformEAlphaMul;
        break;
      case 179:
      case 187:
        result = FSI_D3D1xFL91_FBatchVertexCxformEAlpha;
        break;
      case 180:
      case 188:
        result = FSI_D3D1xFL91_FBatchVertexCxformEAlphaMul;
        break;
      case 193:
      case 201:
        result = FSI_D3D1xFL91_FVertexCxformAc;
        break;
      case 194:
      case 202:
        result = FSI_D3D1xFL91_FVertexCxformAcMul;
        break;
      case 195:
      case 203:
        result = FSI_D3D1xFL91_FBatchVertexCxformAc;
        break;
      case 196:
      case 204:
        result = FSI_D3D1xFL91_FBatchVertexCxformAcMul;
        break;
      case 225:
      case 233:
        result = FSI_D3D1xFL91_FVertexCxformAcEAlpha;
        break;
      case 226:
      case 234:
        result = FSI_D3D1xFL91_FVertexCxformAcEAlphaMul;
        break;
      case 227:
      case 235:
        result = FSI_D3D1xFL91_FBatchVertexCxformAcEAlpha;
        break;
      case 228:
      case 236:
        result = FSI_D3D1xFL91_FBatchVertexCxformAcEAlphaMul;
        break;
      default:
        return 0;
    }
  }
  return result;
}
