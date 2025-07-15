unsigned __int8 *__userpurge Scaleform::Render::D3D1x::MeshBuffer::Lock@<eax>(
        Scaleform::Render::D3D1x::MeshBuffer *this@<esi>,
        Scaleform::Render::D3D1x::MeshBuffer::LockList *lockedBuffers@<edi>,
        ID3D11DeviceContext *pcontext)
{
  if ( !this->pData )
  {
    if ( !this->DoLock(this, pcontext) )
      return 0;
    this->pNextLock = lockedBuffers->pFirst;
    lockedBuffers->pFirst = this;
  }
  return (unsigned __int8 *)this->pData;
}
