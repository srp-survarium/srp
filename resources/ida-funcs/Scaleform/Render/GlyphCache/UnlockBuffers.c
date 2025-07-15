void __thiscall Scaleform::Render::GlyphCache::UnlockBuffers(Scaleform::Render::GlyphCache *this)
{
  unsigned int v2; // edi
  unsigned int *p_DataSize; // esi
  int v4; // eax
  int v5; // ecx

  if ( this->Queue.Notifiers.pHeapOrPtr == (void *)1 )
    Scaleform::Render::GlyphCache::partialUpdateTextures((Scaleform::Render::GlyphCache *)((char *)this - 8));
  v2 = 0;
  if ( this->TextureWidth )
  {
    p_DataSize = &this->Textures[0].Data.Plane0.DataSize;
    while ( 1 )
    {
      v4 = *(p_DataSize - 14);
      if ( v4 )
        break;
      if ( *((_BYTE *)p_DataSize + 12) )
      {
        (*(void (__fastcall **)(unsigned int))(*(_DWORD *)p_DataSize[1] + 72))(p_DataSize[1]);
LABEL_11:
        *((_BYTE *)p_DataSize + 12) = 0;
      }
LABEL_12:
      ++v2;
      p_DataSize += 20;
      if ( v2 >= this->TextureWidth )
        goto LABEL_13;
    }
    if ( v4 != 2 || !*((_BYTE *)p_DataSize + 12) )
      goto LABEL_12;
    (*(void (__thiscall **)(unsigned int))(*(_DWORD *)*p_DataSize + 72))(*p_DataSize);
    v5 = (*(int (__thiscall **)(unsigned int, _DWORD))(*(_DWORD *)*p_DataSize + 84))(*p_DataSize, *(p_DataSize - 13));
    (*(void (__fastcall **)(int))(*(_DWORD *)v5 + 68))(v5);
    goto LABEL_11;
  }
LABEL_13:
  this->Notifier.pCache->__vftable = (Scaleform::Render::CacheBase_vtbl *)((int)this->Notifier.pCache->__vftable & ~2u);
}
