void __thiscall Scaleform::GFx::AS3::MovieRoot::CreateArray(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::Value *pvalue)
{
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> result; // [esp+4h] [ebp-18h] BYREF
  Scaleform::GFx::AS3::Value::V2U v5; // [esp+8h] [ebp-14h]
  Scaleform::GFx::AS3::Value arr; // [esp+Ch] [ebp-10h] BYREF

  LODWORD(arr.value.VNumber) = (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array>)Scaleform::GFx::AS3::VM::MakeArray(
                                                                                                 this->pAVM.pObject,
                                                                                                 &result)->pV;
  arr.value.VS._2 = v5;
  arr.Bonus.pWeakProxy = 0;
  arr.Flags = 12;
  Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(this, &arr, (Scaleform::GFx::ASStringNode *)pvalue);
  if ( (arr.Flags & 0x1F) > 9 )
  {
    if ( (arr.Flags & 0x200) != 0 )
    {
      pWeakProxy = arr.Bonus.pWeakProxy;
      --arr.Bonus.pWeakProxy->RefCount;
      if ( !pWeakProxy->RefCount )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&arr);
    }
  }
}
