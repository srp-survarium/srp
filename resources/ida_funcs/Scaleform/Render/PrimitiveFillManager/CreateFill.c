Scaleform::Render::PrimitiveFill *__thiscall Scaleform::Render::PrimitiveFillManager::CreateFill(
        Scaleform::Render::PrimitiveFillManager *this,
        const Scaleform::Render::PrimitiveFillData *initdata)
{
  Scaleform::HashSetLH<Scaleform::Render::PrimitiveFill *,Scaleform::Render::PrimitiveFill::PtrHashFunctor,Scaleform::Render::PrimitiveFill::PtrHashFunctor,2,Scaleform::HashsetCachedEntry<Scaleform::Render::PrimitiveFill *,Scaleform::Render::PrimitiveFill::PtrHashFunctor> > *p_FillSet; // ebx
  Scaleform::Render::PrimitiveFill *v4; // esi
  Scaleform::Render::PrimitiveFill *result; // eax
  Scaleform::Render::PrimitiveFill *v6; // esi
  Scaleform::Render::PrimitiveFill *fill; // [esp+Ch] [ebp-4h] BYREF

  p_FillSet = &this->FillSet;
  fill = 0;
  if ( Scaleform::HashSetBase<Scaleform::Render::PrimitiveFill *,Scaleform::Render::PrimitiveFill::PtrHashFunctor,Scaleform::Render::PrimitiveFill::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Render::PrimitiveFill *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::PrimitiveFill *,Scaleform::Render::PrimitiveFill::PtrHashFunctor>>::GetAlt<Scaleform::Render::PrimitiveFillData>(
         &this->FillSet,
         initdata,
         &fill) )
  {
    v4 = fill;
    ++fill->RefCount;
    return v4;
  }
  else
  {
    result = this->pHAL->CreatePrimitiveFill(this->pHAL, initdata);
    v6 = result;
    fill = result;
    if ( result )
    {
      Scaleform::HashSet<Scaleform::Render::PrimitiveFill *,Scaleform::Render::PrimitiveFill::PtrHashFunctor,Scaleform::Render::PrimitiveFill::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Render::PrimitiveFill *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::PrimitiveFill *,Scaleform::Render::PrimitiveFill::PtrHashFunctor>>::Add<Scaleform::Render::PrimitiveFill *>(
        p_FillSet,
        &fill);
      v6->pManager = this;
      return v6;
    }
  }
  return result;
}


Scaleform::Render::PrimitiveFill *__thiscall Scaleform::Render::PrimitiveFillManager::CreateFill(
        Scaleform::Render::PrimitiveFillManager *this,
        const Scaleform::Render::FillData *initdata,
        Scaleform::Ptr<Scaleform::Render::Image> *gradientImg,
        Scaleform::Render::TextureManager *mng,
        float morphRatio)
{
  Scaleform::Render::FillType Type; // eax
  Scaleform::Render::PrimitiveFill *v7; // eax
  Scaleform::Render::PrimitiveFill *v8; // esi
  Scaleform::Render::PrimitiveFill *result; // eax
  unsigned int Color; // eax
  const Scaleform::Render::VertexFormat *pVFormat; // ecx
  Scaleform::GFx::Resource *v12; // eax
  Scaleform::Render::PrimitiveFill *v13; // esi
  Scaleform::Render::Image *GradientImage; // ebp
  Scaleform::GFx::Resource *v15; // eax
  Scaleform::Render::PrimitiveFill *v16; // esi
  unsigned __int8 Fill; // [esp-8h] [ebp-4Ch]
  Scaleform::Render::PrimitiveFillData data; // [esp+14h] [ebp-30h] BYREF
  Scaleform::Render::PrimitiveFillData v19; // [esp+2Ch] [ebp-18h] BYREF

  Type = initdata->Type;
  switch ( initdata->Type )
  {
    case Fill_Mask:
      data.Type = PrimFill_Mask;
      data.SolidColor.Raw = 0;
      goto LABEL_3;
    case Fill_SolidColor:
      Color = initdata->Color;
      data.Type = PrimFill_SolidColor;
      data.SolidColor.Raw = Color;
      goto LABEL_3;
    case Fill_VColor:
    case Fill_VColor_TestKey:
      pVFormat = initdata->pVFormat;
      data.Type = initdata->PrimFill;
      data.SolidColor.Raw = 0;
      data.FillModes[0].Fill = 0;
      data.FillModes[1].Fill = 0;
      data.Textures[0].pObject = 0;
      data.Textures[1].pObject = 0;
      data.pFormat = pVFormat;
      if ( Type == Fill_VColor_TestKey )
        data.SolidColor.Raw = initdata->Color;
      v7 = Scaleform::Render::PrimitiveFillManager::CreateFill(this, &data);
      goto LABEL_4;
    case Fill_Image:
      if ( initdata->Color
        && (v12 = (Scaleform::GFx::Resource *)(*(int (__thiscall **)(unsigned int, Scaleform::Render::TextureManager *))(*(_DWORD *)initdata->Color + 84))(
                                                initdata->Color,
                                                mng)) != 0 )
      {
        Scaleform::Render::PrimitiveFillData::PrimitiveFillData(
          &v19,
          initdata->PrimFill,
          initdata->pVFormat,
          v12,
          initdata->FillMode,
          0,
          0);
        v13 = Scaleform::Render::PrimitiveFillManager::CreateFill(this, &v19);
        Scaleform::Render::PrimitiveFillData::~PrimitiveFillData(&v19);
        result = v13;
      }
      else
      {
        data.Type = PrimFill_SolidColor;
        data.SolidColor.Raw = -65536;
LABEL_3:
        data.pFormat = initdata->pVFormat;
        data.Textures[1].pObject = 0;
        data.Textures[0].pObject = 0;
        data.FillModes[1].Fill = 0;
        data.FillModes[0].Fill = 0;
        v7 = Scaleform::Render::PrimitiveFillManager::CreateFill(this, &data);
LABEL_4:
        v8 = v7;
        Scaleform::Render::PrimitiveFillData::~PrimitiveFillData(&data);
        result = v8;
      }
      break;
    case Fill_Gradient:
      GradientImage = Scaleform::Render::PrimitiveFillManager::createGradientImage(
                        this,
                        initdata->pGradient,
                        morphRatio);
      if ( gradientImg->pObject )
        gradientImg->pObject->Release(gradientImg->pObject);
      gradientImg->pObject = GradientImage;
      if ( !GradientImage )
        goto LABEL_17;
      Fill = initdata->FillMode.Fill;
      v15 = (Scaleform::GFx::Resource *)GradientImage->GetTexture(GradientImage, mng);
      Scaleform::Render::PrimitiveFillData::PrimitiveFillData(
        &v19,
        initdata->PrimFill,
        initdata->pVFormat,
        v15,
        (Scaleform::Render::ImageFillMode)Fill,
        0,
        0);
      v16 = Scaleform::Render::PrimitiveFillManager::CreateFill(this, &v19);
      Scaleform::Render::PrimitiveFillData::~PrimitiveFillData(&v19);
      result = v16;
      break;
    default:
LABEL_17:
      result = 0;
      break;
  }
  return result;
}
