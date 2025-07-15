void __thiscall Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter::AS3Constructor(
        Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter *this,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Instances::fl::Array *VInt; // eax
  Scaleform::GFx::AS3::Traits *pObject; // edx
  Scaleform::GFx::AS3::Value result; // [esp+0h] [ebp-10h] BYREF

  if ( argc )
  {
    if ( (argv->Flags & 0x1F) - 12 <= 3 )
    {
      VInt = (Scaleform::GFx::AS3::Instances::fl::Array *)argv->value.VS._1.VInt;
      if ( VInt )
      {
        pObject = VInt->pTraits.pObject;
        if ( pObject->TraitsType == Traits_Array && (pObject->Flags & 0x20) == 0 )
        {
          result.Flags = 0;
          result.Bonus.pWeakProxy = 0;
          Scaleform::GFx::AS3::Instances::fl_filters::ColorMatrixFilter::matrixSet(this, &result, VInt);
          if ( (result.Flags & 0x1F) > 9 )
          {
            if ( (result.Flags & 0x200) != 0 )
              Scaleform::GFx::AS3::Value::ReleaseWeakRef(&result);
            else
              Scaleform::GFx::AS3::Value::ReleaseInternal(&result);
          }
        }
      }
    }
  }
}
