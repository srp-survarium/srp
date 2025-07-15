void Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__()
{
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax

  if ( (v.Flags & 0x1F) > 9 )
  {
    if ( (v.Flags & 0x200) != 0 )
    {
      pWeakProxy = v.Bonus.pWeakProxy;
      --v.Bonus.pWeakProxy->RefCount;
      if ( !pWeakProxy->RefCount )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
      v.Flags &= 0xFFFFFDE0;
      v.Bonus.pWeakProxy = 0;
      v.value.VNumber = 0.0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
    }
  }
}
