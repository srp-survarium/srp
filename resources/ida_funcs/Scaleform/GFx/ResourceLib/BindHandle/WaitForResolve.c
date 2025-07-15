Scaleform::GFx::Resource *__thiscall Scaleform::GFx::ResourceLib::BindHandle::WaitForResolve(
        Scaleform::GFx::ResourceLib::BindHandle *this)
{
  Scaleform::GFx::Resource *pResource; // edi
  Scaleform::GFx::Resource *Value; // ebx

  if ( this->State == RS_Available )
  {
    InterlockedExchangeAdd(&this->pResource->RefCount.Value, 1);
    return this->pResource;
  }
  else if ( this->State == RS_Error )
  {
    return 0;
  }
  else
  {
    pResource = this->pResource;
    Scaleform::Event::Wait((Scaleform::Event *)&pResource[2].pLib, 0xFFFFFFFF);
    if ( pResource[1].RefCount.Value )
      InterlockedExchangeAdd((volatile LONG *)(pResource[1].RefCount.Value + 4), 1);
    Value = (Scaleform::GFx::Resource *)pResource[1].RefCount.Value;
    if ( Value )
    {
      this->State = RS_Available;
      this->pResource = Value;
      InterlockedExchangeAdd(&Value->RefCount.Value, 1);
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pResource);
      return Value;
    }
    else
    {
      this->State = RS_Error;
      return 0;
    }
  }
}
