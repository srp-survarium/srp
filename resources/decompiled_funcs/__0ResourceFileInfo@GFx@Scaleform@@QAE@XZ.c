void __thiscall Scaleform::GFx::ResourceFileInfo::ResourceFileInfo(Scaleform::GFx::ResourceFileInfo *this)
{
  this->RefCount = 1;
  this->__vftable = (Scaleform::GFx::ResourceFileInfo_vtbl *)&Scaleform::GFx::ResourceFileInfo::`vftable';
  Scaleform::String::String(&this->FileName);
  this->Format = File_Unknown;
  this->pExporterInfo = 0;
}
