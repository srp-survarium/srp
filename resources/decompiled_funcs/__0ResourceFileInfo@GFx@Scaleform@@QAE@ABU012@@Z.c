void __thiscall Scaleform::GFx::ResourceFileInfo::ResourceFileInfo(
        Scaleform::GFx::ResourceFileInfo *this,
        const Scaleform::GFx::ResourceFileInfo *src)
{
  this->RefCount = 1;
  this->__vftable = (Scaleform::GFx::ResourceFileInfo_vtbl *)&Scaleform::GFx::ResourceFileInfo::`vftable';
  Scaleform::String::String(&this->FileName, &src->FileName);
  this->Format = src->Format;
  this->pExporterInfo = src->pExporterInfo;
}
