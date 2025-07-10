void __thiscall Scaleform::GFx::Resource::Release(Scaleform::GFx::Resource *this)
{
  Scaleform::GFx::ResourceLibBase *pLib; // ecx

  if ( InterlockedExchangeAdd(&this->RefCount.Value, -1) == 1 )
  {
    pLib = this->pLib;
    if ( pLib )
    {
      pLib->RemoveResourceOnRelease(pLib, this);
      this->pLib = 0;
    }
    ((void (__thiscall *)(Scaleform::GFx::Resource *, int))this->~Scaleform::GFx::Resource)(this, 1);
  }
}
