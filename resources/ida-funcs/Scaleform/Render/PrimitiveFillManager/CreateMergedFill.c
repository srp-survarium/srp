Scaleform::Render::PrimitiveFill *__thiscall Scaleform::Render::PrimitiveFillManager::CreateMergedFill(
        Scaleform::Render::PrimitiveFillManager *this,
        unsigned int mergeFlags,
        const Scaleform::Render::VertexFormat *vformat,
        const Scaleform::Render::FillData *fd0,
        const Scaleform::Render::FillData *fd1,
        Scaleform::Ptr<Scaleform::Render::Image> *gradientImg0,
        Scaleform::Ptr<Scaleform::Render::Image> *gradientImg1,
        Scaleform::Render::TextureManager *textureManager,
        float morphRatio)
{
  Scaleform::Render::GradientData *pGradient; // ebx
  const Scaleform::Render::FillData *v10; // ebp
  Scaleform::Render::FillType Type; // esi
  Scaleform::Render::FillType v12; // edi
  Scaleform::Render::Image *GradientImage; // esi
  Scaleform::Render::Image *v14; // edi
  Scaleform::GFx::Resource *v15; // eax
  Scaleform::Render::Texture *v16; // esi
  unsigned __int8 Fill; // cl
  Scaleform::GFx::Resource *v18; // eax
  Scaleform::Render::Texture *v19; // esi
  unsigned __int8 v20; // dl
  Scaleform::Render::PrimitiveFill *v21; // esi
  Scaleform::Render::PrimitiveFill *result; // eax
  const Scaleform::Render::VertexFormat **p_pFormat; // esi
  int i; // edi
  Scaleform::RefCountVImpl *v25; // ecx
  Scaleform::Render::Image *img1; // [esp+14h] [ebp-20h]
  Scaleform::Render::PrimitiveFillManager *v27; // [esp+18h] [ebp-1Ch]
  Scaleform::Render::PrimitiveFillData data; // [esp+1Ch] [ebp-18h] BYREF

  pGradient = fd0->pGradient;
  v10 = fd1;
  Type = fd0->Type;
  v12 = fd1->Type;
  v27 = this;
  img1 = fd1->pImage;
  if ( fd0->Type == Fill_Gradient )
  {
    GradientImage = Scaleform::Render::PrimitiveFillManager::createGradientImage(this, pGradient, morphRatio);
    if ( gradientImg0->pObject )
      gradientImg0->pObject->Release(gradientImg0->pObject);
    this = v27;
    gradientImg0->pObject = GradientImage;
    v10 = fd1;
    pGradient = (Scaleform::Render::GradientData *)GradientImage;
    Type = Fill_Image;
  }
  if ( v12 == Fill_Gradient )
  {
    v14 = Scaleform::Render::PrimitiveFillManager::createGradientImage(this, v10->pGradient, morphRatio);
    if ( gradientImg1->pObject )
      gradientImg1->pObject->Release(gradientImg1->pObject);
    gradientImg1->pObject = v14;
    v10 = fd1;
    img1 = v14;
    v12 = Fill_Image;
  }
  if ( Type == Fill_VColor_TestKey )
    Type = Fill_VColor;
  if ( v12 == Fill_VColor_TestKey )
    v12 = Fill_VColor;
  data.Type = Scaleform::Render::GetMergedFillType(Type, v12, mergeFlags);
  data.SolidColor.Raw = 0;
  data.FillModes[0].Fill = 0;
  data.FillModes[1].Fill = 0;
  data.Textures[0].pObject = 0;
  data.Textures[1].pObject = 0;
  data.pFormat = vformat;
  switch ( data.Type )
  {
    case PrimFill_Mask:
      goto $LN8_63;
    case PrimFill_SolidColor:
      data.SolidColor.Raw = fd0->Color;
      goto $LN8_63;
    case PrimFill_VColor:
    case PrimFill_VColor_EAlpha:
      if ( fd0->Type == Fill_VColor_TestKey )
        data.SolidColor.Raw = fd0->Color;
      goto $LN8_63;
    case PrimFill_Texture:
    case PrimFill_Texture_EAlpha:
    case PrimFill_Texture_VColor:
    case PrimFill_Texture_VColor_EAlpha:
      goto $LN60_1;
    case PrimFill_2Texture:
    case PrimFill_2Texture_EAlpha:
      v15 = (Scaleform::GFx::Resource *)img1->GetTexture(img1, textureManager);
      v16 = (Scaleform::Render::Texture *)v15;
      if ( v15 )
        Scaleform::RefCountImpl::AddRef(v15);
      Fill = v10->FillMode.Fill;
      data.Textures[1].pObject = v16;
      data.FillModes[1].Fill = Fill;
$LN60_1:
      v18 = (Scaleform::GFx::Resource *)((int (__thiscall *)(Scaleform::Render::GradientData *, Scaleform::Render::TextureManager *))pGradient->__vftable[21].~Scaleform::Render::GradientData)(
                                          pGradient,
                                          textureManager);
      v19 = (Scaleform::Render::Texture *)v18;
      if ( v18 )
        Scaleform::RefCountImpl::AddRef(v18);
      v20 = fd0->FillMode.Fill;
      data.Textures[0].pObject = v19;
      data.FillModes[0].Fill = v20;
$LN8_63:
      v21 = Scaleform::Render::PrimitiveFillManager::CreateFill(v27, &data);
      Scaleform::Render::PrimitiveFillData::~PrimitiveFillData(&data);
      result = v21;
      break;
    default:
      p_pFormat = &data.pFormat;
      for ( i = 1; i >= 0; --i )
      {
        v25 = (Scaleform::RefCountVImpl *)*--p_pFormat;
        if ( v25 )
          Scaleform::RefCountImpl::Release(v25);
      }
      result = 0;
      break;
  }
  return result;
}
