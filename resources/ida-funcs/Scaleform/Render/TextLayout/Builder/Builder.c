void __thiscall Scaleform::Render::TextLayout::Builder::Builder(
        Scaleform::Render::TextLayout::Builder *this,
        Scaleform::MemoryHeap *heap)
{
  this->Param.TextParam.GlyphIndex = 0;
  this->Param.TextParam.FontSize = 0;
  this->Param.TextParam.Flags = 0;
  this->Param.TextParam.BlurX = 0;
  this->Param.TextParam.BlurY = 0;
  this->Param.TextParam.pFont = 0;
  this->Param.TextParam.BlurStrength = 16;
  this->Param.ShadowParam.pFont = 0;
  this->Param.ShadowParam.GlyphIndex = 0;
  this->Param.ShadowParam.FontSize = 0;
  this->Param.ShadowParam.Flags = 0;
  this->Param.ShadowParam.BlurX = 0;
  this->Param.ShadowParam.BlurY = 0;
  this->Param.ShadowParam.BlurStrength = 16;
  this->Param.ShadowOffsetX = 0.0;
  this->Param.ShadowOffsetY = 0.0;
  this->Param.ShadowColor = 0;
  this->Bounds.x1 = 0.0;
  this->Bounds.y1 = 0.0;
  this->Bounds.x2 = 0.0;
  this->Bounds.y2 = 0.0;
  this->ClipBox.x1 = 0.0;
  this->ClipBox.y1 = 0.0;
  this->ClipBox.x2 = 0.0;
  this->ClipBox.y2 = 0.0;
  this->Data.Data = this->Data.Static;
  this->Data.pHeap = heap;
  this->Data.Size = 0;
  this->Data.Reserved = 1024;
  this->Fonts.Data = this->Fonts.Static;
  this->Fonts.pHeap = heap;
  this->Fonts.Size = 0;
  this->Fonts.Reserved = 32;
  this->Images.pHeap = heap;
  this->Images.Reserved = 32;
  this->Images.Size = 0;
  this->Images.Data = this->Images.Static;
  this->RefCntData.pHeap = heap;
  this->RefCntData.Reserved = 32;
  this->RefCntData.Size = 0;
  this->RefCntData.Data = this->RefCntData.Static;
  this->LastScale = 1.0;
  this->LastFont = 0;
}
