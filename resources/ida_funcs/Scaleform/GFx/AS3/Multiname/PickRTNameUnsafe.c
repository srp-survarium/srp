void __thiscall Scaleform::GFx::AS3::Multiname::PickRTNameUnsafe(
        Scaleform::GFx::AS3::Multiname *this,
        Scaleform::GFx::AS3::VSBase *vs)
{
  Scaleform::GFx::AS3::Value *pCurrent; // eax
  Scaleform::GFx::AS3::Value::V1U v3; // edx
  int v4; // esi
  Scaleform::GFx::AS3::Value *v5; // esi
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax

  pCurrent = vs->pCurrent;
  if ( (vs->pCurrent->Flags & 0x1F) - 12 > 3
    || (v3 = pCurrent->value.VS._1, !v3.VInt)
    || (v4 = *(_DWORD *)(v3.VInt + 20), *(_DWORD *)(v4 + 60) != 12)
    || (*(_DWORD *)(v4 + 56) & 0x20) != 0 )
  {
    this->Name = *pCurrent;
    --vs->pCurrent;
    Scaleform::GFx::AS3::Multiname::PostProcessName(this, 0);
    return;
  }
  Scaleform::GFx::AS3::Multiname::SetFromQName(this, vs->pCurrent);
  v5 = vs->pCurrent;
  if ( (vs->pCurrent->Flags & 0x1F) <= 9 )
  {
LABEL_11:
    --vs->pCurrent;
    return;
  }
  if ( (vs->pCurrent->Flags & 0x200) == 0 )
  {
    Scaleform::GFx::AS3::Value::ReleaseInternal(vs->pCurrent);
    goto LABEL_11;
  }
  pWeakProxy = v5->Bonus.pWeakProxy;
  if ( pWeakProxy->RefCount-- == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
  v5->Flags &= 0xFFFFFDE0;
  v5->Bonus.pWeakProxy = 0;
  v5->value.VS._1.VInt = 0;
  v5->value.VS._2.VObj = 0;
  --vs->pCurrent;
}
