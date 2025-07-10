void __thiscall Scaleform::GFx::TextFieldDef::TextFieldDef(Scaleform::GFx::TextFieldDef *this)
{
  float v2; // [esp+8h] [ebp-4h]

  this->__vftable = (Scaleform::GFx::TextFieldDef_vtbl *)&Scaleform::GFx::Resource::`vftable';
  this->RefCount.Value = 1;
  this->pLib = 0;
  this->Id.Id = 0x40000;
  this->__vftable = (Scaleform::GFx::TextFieldDef_vtbl *)&Scaleform::GFx::TextFieldDef::`vftable';
  this->pFont.HType = RH_Pointer;
  this->pFont.BindIndex = 0;
  this->FontId.Id = 0;
  Scaleform::StringLH::StringLH(&this->FontClass);
  this->TextRect.x1 = 0.0;
  this->TextRect.y1 = 0.0;
  this->TextRect.x2 = 0.0;
  this->TextRect.y2 = 0.0;
  this->MaxLength = 0;
  this->TextHeight = 1.0;
  this->LeftMargin = 0.0;
  this->RightMargin = 0.0;
  this->Indent = 0.0;
  this->Leading = 0.0;
  Scaleform::StringLH::StringLH(&this->DefaultText);
  Scaleform::StringLH::StringLH(&this->VariableName);
  this->Alignment = ALIGN_LEFT;
  this->Flags = 0;
  this->ColorV.Channels.Red = 0;
  this->ColorV.Channels.Green = 0;
  this->ColorV.Channels.Blue = 0;
  this->ColorV.Channels.Alpha = -1;
  this->TextRect.x1 = 0.0;
  this->TextRect.y1 = 0.0;
  v2 = 0.0 + 0.0;
  this->TextRect.x2 = v2;
  this->TextRect.y2 = v2;
}
