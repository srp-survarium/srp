void __thiscall Scaleform::GFx::AS3::MovieRoot::SuspendGC(Scaleform::GFx::AS3::MovieRoot *this, bool suspend)
{
  Scaleform::GFx::AS3::ASRefCountCollector *pObject; // eax

  pObject = this->MemContext.pObject->ASGC.pObject;
  if ( suspend )
    ++pObject->SuspendCnt;
  else
    --pObject->SuspendCnt;
}
