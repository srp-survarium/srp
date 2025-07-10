bool __thiscall Scaleform::GFx::AS3::Instances::fl_net::URLLoader::IsLoadingText(
        Scaleform::GFx::AS3::Instances::fl_net::URLLoader *this)
{
  return strcmp(this->dataFormat.pNode->pData, "text") == 0;
}
