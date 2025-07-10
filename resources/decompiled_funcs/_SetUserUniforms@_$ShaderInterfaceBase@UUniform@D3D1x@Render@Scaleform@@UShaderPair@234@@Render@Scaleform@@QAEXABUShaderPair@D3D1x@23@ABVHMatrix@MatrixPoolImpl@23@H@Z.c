void __userpurge Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUserUniforms(
        const Scaleform::Render::MatrixPoolImpl::HMatrix *m@<eax>,
        Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *this,
        const Scaleform::Render::D3D1x::ShaderPair *sd,
        unsigned int batch)
{
  Scaleform::Render::MatrixPoolImpl::DataHeader *pHeader; // eax
  float *v5; // edi
  signed int i; // ebx
  unsigned int UniformSize; // eax
  unsigned int v8; // ebp
  Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *v9; // edx
  Scaleform::Render::Texture *v10; // eax
  Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair> *v11; // [esp+0h] [ebp-28h]
  unsigned int Height; // [esp+14h] [ebp-14h]
  float scaled[4]; // [esp+18h] [ebp-10h] BYREF

  pHeader = m->pHandle->pHeader;
  if ( (pHeader->Format & 8) != 0 )
    v5 = (float *)(&pHeader[1].RefCount + 4 * (unsigned __int8)byte_9B2B73[5 * (pHeader->Format & 0xF)]);
  else
    v5 = 0;
  for ( i = 0; i < 15; ++i )
  {
    if ( (Scaleform::Render::D3D1x::Uniform::UniformFlags[i] & 1) == 0 )
    {
      UniformSize = Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::GetUniformSize(
                      v11,
                      sd,
                      i);
      v8 = UniformSize;
      if ( UniformSize )
      {
        if ( (Scaleform::Render::D3D1x::Uniform::UniformFlags[i] & 2) != 0 && UniformSize <= 4 )
        {
          v9 = this;
          v10 = this->Textures[0];
          if ( v10 )
          {
            Height = v10->ImgSize.Height;
            scaled[0] = 1.0 / (double)v10->ImgSize.Width * *v5;
            scaled[2] = v5[2];
            scaled[3] = v5[3];
            scaled[1] = 1.0 / (double)Height * v5[1];
            Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
              sd,
              i,
              0,
              this,
              scaled,
              v8,
              batch);
LABEL_13:
            v5 += v8;
            continue;
          }
        }
        else
        {
          v9 = this;
        }
        Scaleform::Render::ShaderInterfaceBase<Scaleform::Render::D3D1x::Uniform,Scaleform::Render::D3D1x::ShaderPair>::SetUniform(
          sd,
          i,
          0,
          v9,
          v5,
          v8,
          batch);
        goto LABEL_13;
      }
    }
  }
}
