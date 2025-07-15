void __thiscall Scaleform::GFx::ImageCreateExportInfo::ImageCreateExportInfo(
        Scaleform::GFx::ImageCreateExportInfo *this,
        Scaleform::MemoryHeap *heap,
        unsigned int imageUse,
        Scaleform::GFx::Resource::ResourceUse resourceUse)
{
  this->pHeap = heap;
  this->Use = imageUse;
  this->Type = Create_ExportImage;
  this->RUse = resourceUse;
  this->pLog = 0;
  this->pFileOpener = 0;
  this->pIFHRegistry = 0;
  this->pMovie = 0;
  Scaleform::String::String(&this->ExportName);
}
