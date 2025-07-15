void __thiscall Scaleform::GFx::FontData::FontData(Scaleform::GFx::FontData *this, char *name, unsigned int fontFlags)
{
  char *v4; // edi

  this->Ascent = 0.0;
  this->__vftable = (Scaleform::GFx::FontData_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->Descent = 0.0;
  this->__vftable = (Scaleform::GFx::FontData_vtbl *)&Scaleform::Render::Font::`vftable';
  this->Flags = fontFlags;
  this->Leading = 0.0;
  this->RefCount = 1;
  this->UpperCaseTop = 0;
  this->LowerCaseTop = 0;
  this->hRef.pManager.Value = 0;
  this->hRef.pFontHandle = 0;
  this->__vftable = (Scaleform::GFx::FontData_vtbl *)&Scaleform::GFx::FontData::`vftable';
  this->Name = 0;
  this->pTGData.pObject = 0;
  this->Glyphs.Data.Data = 0;
  this->Glyphs.Data.Size = 0;
  this->Glyphs.Data.Policy.Capacity = 0;
  this->CodeTable.mHash.pTable = 0;
  this->AdvanceTable.Data.Data = 0;
  this->AdvanceTable.Data.Size = 0;
  this->AdvanceTable.Data.Policy.Capacity = 0;
  this->KerningPairs.mHash.pTable = 0;
  v4 = (char *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, strlen(name) + 1, 0);
  this->Name = v4;
  if ( v4 )
    strcpy_s((int)v4, v4, strlen(name) + 1, name);
  this->Flags |= 0x2000u;
}


void __thiscall Scaleform::GFx::FontData::FontData(Scaleform::GFx::FontData *this)
{
  this->Ascent = 0.0;
  this->__vftable = (Scaleform::GFx::FontData_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->Descent = 0.0;
  this->__vftable = (Scaleform::GFx::FontData_vtbl *)&Scaleform::Render::Font::`vftable';
  this->Leading = 0.0;
  this->RefCount = 1;
  this->Flags = 0;
  this->LowerCaseTop = 0;
  this->UpperCaseTop = 0;
  this->hRef.pManager.Value = 0;
  this->hRef.pFontHandle = 0;
  this->__vftable = (Scaleform::GFx::FontData_vtbl *)&Scaleform::GFx::FontData::`vftable';
  this->Name = 0;
  this->pTGData.pObject = 0;
  this->Glyphs.Data.Data = 0;
  this->Glyphs.Data.Size = 0;
  this->Glyphs.Data.Policy.Capacity = 0;
  this->CodeTable.mHash.pTable = 0;
  this->AdvanceTable.Data.Data = 0;
  this->AdvanceTable.Data.Size = 0;
  this->AdvanceTable.Data.Policy.Capacity = 0;
  this->KerningPairs.mHash.pTable = 0;
}
