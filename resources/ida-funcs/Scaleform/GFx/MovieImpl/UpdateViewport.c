void __thiscall Scaleform::GFx::MovieImpl::UpdateViewport(Scaleform::GFx::MovieImpl *this)
{
  Scaleform::GFx::MovieDefImpl *pObject; // edx
  int Left; // eax
  int v4; // edi
  Scaleform::GFx::Movie::ScaleModeType ViewScaleMode; // ecx
  float *v6; // eax
  double v7; // st7
  double v8; // st6
  double v9; // st5
  double v10; // st4
  double v11; // st4
  double v12; // st7
  double v13; // st3
  double v14; // rt2
  double v15; // st3
  double v16; // st6
  double v17; // st5
  double v18; // st4
  double v19; // st3
  double v20; // st7
  double v21; // st6
  double v22; // st6
  double v23; // st6
  double v24; // st5
  double v25; // st6
  double v26; // st4
  double v27; // rt1
  double v28; // st4
  double v29; // st7
  double v30; // st6
  double v31; // st7
  Scaleform::GFx::MovieImpl *v32; // ecx
  float v33; // [esp+4h] [ebp-48h]
  float v34; // [esp+8h] [ebp-44h]
  float v35; // [esp+Ch] [ebp-40h]
  float v36; // [esp+Ch] [ebp-40h]
  int Top; // [esp+10h] [ebp-3Ch]
  float v38; // [esp+10h] [ebp-3Ch]
  float v39; // [esp+10h] [ebp-3Ch]
  float v40; // [esp+10h] [ebp-3Ch]
  float v41; // [esp+10h] [ebp-3Ch]
  float v42; // [esp+10h] [ebp-3Ch]
  float v43; // [esp+10h] [ebp-3Ch]
  float v44; // [esp+10h] [ebp-3Ch]
  float v45; // [esp+10h] [ebp-3Ch]
  float v46; // [esp+10h] [ebp-3Ch]
  float v47; // [esp+10h] [ebp-3Ch]
  float v48; // [esp+10h] [ebp-3Ch]
  float v49; // [esp+10h] [ebp-3Ch]
  float v50; // [esp+10h] [ebp-3Ch]
  float v51; // [esp+10h] [ebp-3Ch]
  float v52; // [esp+10h] [ebp-3Ch]
  float v53; // [esp+14h] [ebp-38h]
  float v54; // [esp+14h] [ebp-38h]
  float v55; // [esp+14h] [ebp-38h]
  float v56; // [esp+14h] [ebp-38h]
  float v57; // [esp+14h] [ebp-38h]
  float v58; // [esp+14h] [ebp-38h]
  float v59; // [esp+14h] [ebp-38h]
  float v60; // [esp+14h] [ebp-38h]
  float ViewOffsetX; // [esp+18h] [ebp-34h]
  float ViewOffsetY; // [esp+1Ch] [ebp-30h]
  float ViewScaleX; // [esp+20h] [ebp-2Ch]
  float ViewScaleY; // [esp+24h] [ebp-28h]
  float PixelScale; // [esp+28h] [ebp-24h]
  float v66; // [esp+2Ch] [ebp-20h]
  float v67; // [esp+30h] [ebp-1Ch]
  float v68; // [esp+34h] [ebp-18h]
  float v69; // [esp+38h] [ebp-14h]
  float x1; // [esp+3Ch] [ebp-10h]
  float y1; // [esp+40h] [ebp-Ch]
  float x2; // [esp+44h] [ebp-8h]
  float y2; // [esp+48h] [ebp-4h]

  pObject = this->pMainMovieDef.pObject;
  x1 = this->VisibleFrameRect.x1;
  y1 = this->VisibleFrameRect.y1;
  x2 = this->VisibleFrameRect.x2;
  y2 = this->VisibleFrameRect.y2;
  ViewOffsetX = this->ViewOffsetX;
  ViewOffsetY = this->ViewOffsetY;
  ViewScaleX = this->ViewScaleX;
  ViewScaleY = this->ViewScaleY;
  PixelScale = this->PixelScale;
  if ( pObject )
  {
    Left = this->mViewport.Left;
    Top = this->mViewport.Top;
    v4 = Left + this->mViewport.Width;
    v66 = (double)Left * 20.0;
    ViewScaleMode = this->ViewScaleMode;
    v67 = (double)Top * 20.0;
    v6 = (float *)pObject->pBindData.pObject->pDataDef.pObject->pData.pObject;
    v68 = (double)v4 * 20.0;
    v69 = 20.0 * (double)(Top + this->mViewport.Height);
    v35 = v68 - v66;
    v38 = v69 - v67;
    v33 = v6[18] - v6[16];
    v34 = v6[19] - v6[17];
    v7 = 0.0;
    switch ( ViewScaleMode )
    {
      case SM_NoScale:
        v36 = this->mViewport.AspectRatio * v35 * this->mViewport.Scale;
        v39 = v38 * this->mViewport.Scale;
        v8 = v36;
        v9 = v39;
        v10 = 0.05000000074505806;
        switch ( this->ViewAlignment )
        {
          case Align_Center:
            v40 = v33 * 0.5 - v8 * 0.5;
            v41 = v40 * 0.05000000074505806;
            this->VisibleFrameRect.x1 = (float)(20 * (int)v41);
            v42 = v34 * 0.5 - 0.5 * v9;
            v43 = v42 * 0.05000000074505806;
            this->VisibleFrameRect.y1 = (float)(20 * (int)v43);
            break;
          case Align_TopCenter:
            v44 = v33 * 0.5 - 0.5 * v8;
            v45 = v44 * 0.05000000074505806;
            this->VisibleFrameRect.x1 = (float)(20 * (int)v45);
            v11 = 0.0;
            v12 = 0.05000000074505806;
            this->VisibleFrameRect.y1 = 0.0;
            goto LABEL_10;
          case Align_BottomCenter:
            v46 = v33 * 0.5 - 0.5 * v8;
            v47 = v46 * 0.05000000074505806;
            v15 = (double)(20 * (int)v47);
            goto LABEL_13;
          case Align_CenterLeft:
            v11 = 0.0;
            v12 = 0.05000000074505806;
            this->VisibleFrameRect.x1 = 0.0;
            v48 = v34 * 0.5 - 0.5 * v9;
            v49 = v48 * 0.05000000074505806;
            v13 = (double)(20 * (int)v49);
            goto LABEL_9;
          case Align_CenterRight:
            this->VisibleFrameRect.x1 = v33 - v8;
            v50 = v34 * 0.5 - 0.5 * v9;
            v51 = v50 * 0.05000000074505806;
            this->VisibleFrameRect.y1 = (float)(20 * (int)v51);
            break;
          case Align_TopLeft:
            v11 = 0.0;
            v12 = 0.05000000074505806;
            this->VisibleFrameRect.x1 = 0.0;
            this->VisibleFrameRect.y1 = 0.0;
            goto LABEL_10;
          case Align_TopRight:
            this->VisibleFrameRect.x1 = v33 - v8;
            v11 = 0.0;
            v12 = 0.05000000074505806;
            this->VisibleFrameRect.y1 = 0.0;
            goto LABEL_10;
          case Align_BottomLeft:
            v11 = 0.0;
            v12 = 0.05000000074505806;
            this->VisibleFrameRect.x1 = 0.0;
            v13 = v34 - v9;
LABEL_9:
            this->VisibleFrameRect.y1 = v13;
LABEL_10:
            v14 = v11;
            v10 = v12;
            v7 = v14;
            break;
          case Align_BottomRight:
            v15 = v33 - v8;
LABEL_13:
            this->VisibleFrameRect.x1 = v15;
            this->VisibleFrameRect.y1 = v34 - v9;
            break;
          default:
            break;
        }
        this->VisibleFrameRect.x2 = v8 + this->VisibleFrameRect.x1;
        this->VisibleFrameRect.y2 = v9 + this->VisibleFrameRect.y1;
        this->ViewOffsetX = this->VisibleFrameRect.x1 * v10;
        this->ViewOffsetY = v10 * this->VisibleFrameRect.y1;
        this->ViewScaleX = this->mViewport.AspectRatio * this->mViewport.Scale;
        this->ViewScaleY = this->mViewport.Scale;
        break;
      case SM_ShowAll:
      case SM_NoBorder:
        v53 = this->mViewport.AspectRatio * v35;
        v16 = v38;
        v17 = v33;
        v18 = v34;
        v19 = v53;
        if ( ViewScaleMode == SM_ShowAll && v16 / v18 > v19 / v17
          || ViewScaleMode == SM_NoBorder && v16 / v18 < v19 / v17 )
        {
          v54 = v16 * v17 / v19;
          this->VisibleFrameRect.x1 = 0.0;
          this->VisibleFrameRect.y1 = v18 * 0.5 - 0.5 * v54;
          this->VisibleFrameRect.x2 = this->VisibleFrameRect.x1 + v33;
          this->VisibleFrameRect.y2 = v54 + this->VisibleFrameRect.y1;
          this->ViewOffsetX = 0.0;
          this->ViewOffsetY = this->VisibleFrameRect.y1 * 0.05000000074505806;
          if ( v35 == 0.0 )
            v20 = 0.0;
          else
            v20 = v33 / v35;
          v21 = v20;
          v7 = 0.0;
          v55 = v21;
          this->ViewScaleX = v55;
          this->ViewScaleY = v55 / this->mViewport.AspectRatio;
        }
        else
        {
          v56 = v19 * v18 / v16;
          this->VisibleFrameRect.x1 = v17 * 0.5 - 0.5 * v56;
          this->VisibleFrameRect.y1 = 0.0;
          this->VisibleFrameRect.x2 = v56 + this->VisibleFrameRect.x1;
          this->VisibleFrameRect.y2 = this->VisibleFrameRect.y1 + v18;
          this->ViewOffsetX = this->VisibleFrameRect.x1 * 0.05000000074505806;
          this->ViewOffsetY = 0.0;
          v7 = 0.0;
          if ( 0.0 == v16 )
            v22 = 0.0;
          else
            v22 = v18 / v16;
          v57 = v22;
          this->ViewScaleY = v57;
          this->ViewScaleX = v57 * this->mViewport.AspectRatio;
        }
        break;
      case SM_ExactFit:
        this->VisibleFrameRect.y1 = 0.0;
        this->VisibleFrameRect.x1 = 0.0;
        this->VisibleFrameRect.x2 = this->VisibleFrameRect.x1 + v33;
        this->VisibleFrameRect.y2 = this->VisibleFrameRect.y1 + v34;
        this->ViewOffsetY = 0.0;
        this->ViewOffsetX = 0.0;
        if ( v35 == 0.0 )
        {
          v23 = 0.0;
        }
        else
        {
          v58 = this->VisibleFrameRect.x2 - this->VisibleFrameRect.x1;
          v23 = v58 / v35;
        }
        v24 = v23;
        v25 = 0.0;
        this->ViewScaleX = v24;
        if ( v38 != 0.0 )
        {
          v59 = this->VisibleFrameRect.y2 - this->VisibleFrameRect.y1;
          v25 = v59 / v38;
        }
        this->ViewScaleY = v25;
        break;
      default:
        break;
    }
    if ( v7 == this->ViewScaleY )
      v26 = 0.004999999888241291;
    else
      v26 = 1.0 / this->ViewScaleY;
    v27 = v26;
    v28 = v7;
    v29 = v27;
    if ( v28 == this->ViewScaleX )
      v30 = 0.004999999888241291;
    else
      v30 = 1.0 / this->ViewScaleX;
    v52 = v30;
    v60 = v29;
    if ( v52 <= (double)v60 )
      v52 = v29;
    v31 = v52;
  }
  else
  {
    this->ViewOffsetY = 0.0;
    this->ViewOffsetX = 0.0;
    v31 = 1.0;
    this->ViewScaleY = 1.0;
    this->ViewScaleX = 1.0;
  }
  this->PixelScale = v31;
  Scaleform::GFx::MovieImpl::ResetViewportMatrix(this);
  if ( this->VisibleFrameRect.x1 != x1
    || this->VisibleFrameRect.x2 != x2
    || this->VisibleFrameRect.y1 != y1
    || this->VisibleFrameRect.y2 != y2
    || this->ViewOffsetX != ViewOffsetX
    || this->ViewOffsetY != ViewOffsetY
    || this->ViewScaleX != ViewScaleX
    || this->ViewScaleY != ViewScaleY
    || this->PixelScale != PixelScale )
  {
    Scaleform::GFx::MovieImpl::UpdateViewAndPerspective(v32);
  }
}
