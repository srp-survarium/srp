void __thiscall Scaleform::GFx::AS3::Instances::fl::XMLList::AS3namespace_(
        Scaleform::GFx::AS3::Instances::fl::XMLList *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::CheckResult v5; // [esp+7h] [ebp-1h] BYREF

  if ( Scaleform::GFx::AS3::Instances::fl::XMLList::HasOneItem(this, &v5, "namespace")->Result )
    Scaleform::GFx::AS3::Instances::fl::XML::AS3namespace_(this->List.Data.Data->pObject, result, argc, argv);
}
