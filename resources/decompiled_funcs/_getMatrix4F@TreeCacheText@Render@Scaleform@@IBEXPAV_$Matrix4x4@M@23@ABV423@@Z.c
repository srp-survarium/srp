void __thiscall Scaleform::Render::TreeCacheText::getMatrix4F(
        Scaleform::Render::TreeCacheText *this,
        Scaleform::Render::Matrix4x4<float> *m4,
        const Scaleform::Render::Matrix4x4<float> *viewProj)
{
  Scaleform::Render::MatrixPoolImpl::EntryHandle *pHandle; // eax

  pHandle = this->M.pHandle;
  if ( (pHandle->pHeader->Format & 0x10) != 0 )
    Scaleform::Render::Matrix4x4<float>::MultiplyMatrix(
      m4,
      viewProj,
      (const Scaleform::Render::Matrix3x4<float> *)(&pHandle->pHeader[1].RefCount
                                                  + 4
                                                  * (unsigned __int8)byte_9B2B74[5 * (pHandle->pHeader->Format & 0xF)]));
  else
    Scaleform::Render::Matrix4x4<float>::MultiplyMatrix(m4, viewProj, &Scaleform::Render::Matrix3x4<float>::Identity);
}
