void __thiscall Scaleform::Render::RQCacheInterface::UnlockCaches(Scaleform::Render::RQCacheInterface *this)
{
  unsigned int v2; // esi
  int v3; // edi

  v2 = 0;
  v3 = 1;
  do
  {
    if ( (v3 & this->LockFlags) != 0 )
    {
      if ( this->pCaches[v2] )
        this->pCaches[v2]->UnlockBuffers(this->pCaches[v2]);
    }
    ++v2;
    v3 = __ROL4__(v3, 1);
  }
  while ( v2 < 2 );
}
