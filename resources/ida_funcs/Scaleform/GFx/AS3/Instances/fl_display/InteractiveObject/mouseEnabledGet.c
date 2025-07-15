void __thiscall Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject::mouseEnabledGet(
        Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *this,
        bool *result)
{
  *result = ((LOBYTE(this->pDispObj.pObject->Flags) >> 7 != 0
            ? &this->pDispObj.pObject[1].Id
            : (Scaleform::GFx::ResourceId *)104)->Id
           & 0x1000) == 0;
}
