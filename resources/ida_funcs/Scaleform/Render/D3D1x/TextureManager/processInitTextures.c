void __thiscall Scaleform::Render::D3D1x::TextureManager::processInitTextures(
        Scaleform::Render::D3D1x::TextureManager *this)
{
  Scaleform::List<Scaleform::Render::Texture,Scaleform::Render::Texture> *p_TextureInitQueue; // ebx
  Scaleform::Render::Texture *p_Textures; // eax
  Scaleform::Render::DepthStencilSurface *v4; // ecx
  int v5; // eax
  Scaleform::Render::Texture *pNext; // esi
  bool (__thiscall *Initialize)(Scaleform::Render::Texture *); // eax
  Scaleform::Render::DepthStencilSurface *v8; // eax
  Scaleform::Render::DepthStencilSurface *v9; // ecx
  void (*v10)(void); // eax

  p_TextureInitQueue = &this->TextureInitQueue;
  if ( this == (Scaleform::Render::D3D1x::TextureManager *)-72 )
    p_Textures = 0;
  else
    p_Textures = (Scaleform::Render::Texture *)&this->Textures;
  if ( this->TextureInitQueue.Root.pNext != p_Textures
    || (this == (Scaleform::Render::D3D1x::TextureManager *)-80
      ? (v4 = 0)
      : (v4 = (Scaleform::Render::DepthStencilSurface *)&this->TextureInitQueue),
        this->DepthStencilInitQueue.Root.pNext != v4) )
  {
    while ( 1 )
    {
      v5 = p_TextureInitQueue ? (int)&p_TextureInitQueue[-1] : 0;
      if ( p_TextureInitQueue->Root.pNext == (Scaleform::Render::Texture *)v5 )
        break;
      pNext = this->TextureInitQueue.Root.pNext;
      pNext->pPrev->pNext = pNext->pNext;
      pNext->pNext->pPrev = pNext->pPrev;
      Initialize = pNext->Initialize;
      pNext->pNext = 0;
      pNext->pPrev = 0;
      if ( Initialize(pNext) )
      {
        pNext->pPrev = this->Textures.Root.pPrev;
        pNext->pNext = (Scaleform::Render::Texture *)&this->TextureFormats.Data.Size;
        this->Textures.Root.pPrev->pNext = pNext;
        this->Textures.Root.pPrev = pNext;
      }
    }
    while ( 1 )
    {
      v8 = this == (Scaleform::Render::D3D1x::TextureManager *)-80
         ? 0
         : (Scaleform::Render::DepthStencilSurface *)&this->TextureInitQueue;
      if ( this->DepthStencilInitQueue.Root.pNext == v8 )
        break;
      v9 = this->DepthStencilInitQueue.Root.pNext;
      v9->pPrev->pNext = v9->pNext;
      v9->pNext->pPrev = v9->pPrev;
      v10 = (void (*)(void))v9->Initialize;
      v9->pNext = 0;
      v9->pPrev = 0;
      v10();
    }
    Scaleform::WaitCondition::NotifyAll(&this->pLocks.pObject->TextureInitWC);
  }
}
