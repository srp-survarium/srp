bool __thiscall Scaleform::GFx::AS3::Instances::fl_net::URLLoader::IsLoadingBinary(
        Scaleform::GFx::AS3::Instances::fl_net::URLLoader *this)
{
  return strcmp(this->dataFormat.pNode->pData, "binary") == 0;
}
