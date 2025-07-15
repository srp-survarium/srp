bool __thiscall Scaleform::GFx::AS3::Instances::fl_net::URLLoader::IsLoadingVariables(
        Scaleform::GFx::AS3::Instances::fl_net::URLLoader *this)
{
  return strcmp(this->dataFormat.pNode->pData, "variables") == 0;
}
