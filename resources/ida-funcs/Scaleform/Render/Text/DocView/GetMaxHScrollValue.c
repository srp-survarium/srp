unsigned int __thiscall Scaleform::Render::Text::DocView::GetMaxHScrollValue(Scaleform::Render::Text::DocView *this)
{
  Scaleform::Render::Text::EditorKitBase *pObject; // ecx
  unsigned int TextWidth; // eax
  double v5; // st7
  double v6; // st6
  float v7; // [esp+4h] [ebp-Ch]
  float v8; // [esp+4h] [ebp-Ch]
  int v9; // [esp+8h] [ebp-8h]
  float v10; // [esp+8h] [ebp-8h]

  if ( (this->Flags & 8) != 0 )
    return 0;
  pObject = this->pEditorKit.pObject;
  if ( !pObject || (v9 = 1200, pObject->IsReadOnly(pObject)) )
    v9 = 0;
  TextWidth = this->TextWidth;
  v5 = 0.0;
  if ( TextWidth )
    v7 = (float)TextWidth;
  else
    v7 = 0.0;
  v6 = v7;
  v8 = this->mLineBuffer.Geom.VisibleRect.x2 - this->mLineBuffer.Geom.VisibleRect.x1;
  v10 = v6 - v8 + (double)v9;
  if ( v10 >= 0.0 )
    v5 = v10;
  return (__int64)(float)v5;
}
