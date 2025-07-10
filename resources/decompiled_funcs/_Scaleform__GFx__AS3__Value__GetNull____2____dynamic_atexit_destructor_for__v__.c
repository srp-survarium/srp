void __cdecl Scaleform::GFx::AS3::Value::GetNull_::_2_::_dynamic_atexit_destructor_for__v__()
{
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax

  if ( (v_0.Flags & 0x1F) > 9 )
  {
    if ( (v_0.Flags & 0x200) != 0 )
    {
      pWeakProxy = v_0.Bonus.pWeakProxy;
      --v_0.Bonus.pWeakProxy->RefCount;
      if ( !pWeakProxy->RefCount )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
      v_0.Flags &= 0xFFFFFDE0;
      v_0.Bonus.pWeakProxy = 0;
      v_0.value.VNumber = 0.0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v_0);
    }
  }
}
