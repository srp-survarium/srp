void __thiscall Scaleform::GFx::URLBuilder::LocationInfo::LocationInfo(
        Scaleform::GFx::URLBuilder::LocationInfo *this,
        Scaleform::GFx::URLBuilder::FileUse use,
        const Scaleform::String *filename,
        const Scaleform::String *path)
{
  this->Use = use;
  Scaleform::String::String(&this->FileName, filename);
  Scaleform::String::String(&this->ParentPath, path);
}
