Scaleform::Render::PrimitiveFill *__thiscall Scaleform::Render::PrimitiveFillManager::CreateFill(
        Scaleform::Render::PrimitiveFillManager *this,
        const Scaleform::Render::PrimitiveFillData *initdata)
{
  Scaleform::HashSetLH<Scaleform::Render::PrimitiveFill *,Scaleform::Render::PrimitiveFill::PtrHashFunctor,Scaleform::Render::PrimitiveFill::PtrHashFunctor,2,Scaleform::HashsetCachedEntry<Scaleform::Render::PrimitiveFill *,Scaleform::Render::PrimitiveFill::PtrHashFunctor> > *p_FillSet; // ebx
  Scaleform::Render::PrimitiveFill *v4; // esi
  Scaleform::Render::PrimitiveFill *result; // eax
  Scaleform::Render::PrimitiveFill *v6; // esi
  Scaleform::Render::PrimitiveFill *v7; // [esp+Ch] [ebp-4h] BYREF

  p_FillSet = &this->FillSet;
  v7 = 0;
  if ( Scaleform::HashSetBase<Scaleform::Render::PrimitiveFill *,Scaleform::Render::PrimitiveFill::PtrHashFunctor,Scaleform::Render::PrimitiveFill::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Render::PrimitiveFill *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::PrimitiveFill *,Scaleform::Render::PrimitiveFill::PtrHashFunctor>>::GetAlt<Scaleform::Render::PrimitiveFillData>(
         &this->FillSet,
         initdata,
         &v7) )
  {
    v4 = v7;
    ++v7->RefCount;
    return v4;
  }
  else
  {
    result = this->pHAL->CreatePrimitiveFill(this->pHAL, initdata);
    v6 = result;
    v7 = result;
    if ( result )
    {
      Scaleform::HashSet<Scaleform::Render::PrimitiveFill *,Scaleform::Render::PrimitiveFill::PtrHashFunctor,Scaleform::Render::PrimitiveFill::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Render::PrimitiveFill *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::PrimitiveFill *,Scaleform::Render::PrimitiveFill::PtrHashFunctor>>::Add<Scaleform::Render::PrimitiveFill *>(
        p_FillSet,
        &v7);
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
  Scaleform::AmpServer *Instance; // eax
  Scaleform::AmpStats *v15; // eax
  Scaleform::Render::Image *GradientImage; // ebp
  Scaleform::GFx::Resource *v17; // eax
  Scaleform::Render::PrimitiveFill *v18; // esi
  unsigned __int8 Fill; // [esp-8h] [ebp-4Ch]
  Scaleform::Render::PrimitiveFillData initdataa; // [esp+14h] [ebp-30h] BYREF
  Scaleform::Render::PrimitiveFillData v21; // [esp+2Ch] [ebp-18h] BYREF

  Type = initdata->Type;
  switch ( initdata->Type )
  {
    case Fill_Mask:
      initdataa.Type = PrimFill_Mask;
      initdataa.SolidColor.Raw = 0;
      goto LABEL_3;
    case Fill_SolidColor:
      Color = initdata->Color;
      initdataa.Type = PrimFill_SolidColor;
      initdataa.SolidColor.Raw = Color;
      goto LABEL_3;
    case Fill_VColor:
    case Fill_VColor_TestKey:
      pVFormat = initdata->pVFormat;
      initdataa.Type = initdata->PrimFill;
      initdataa.SolidColor.Raw = 0;
      initdataa.FillModes[0].Fill = 0;
      initdataa.FillModes[1].Fill = 0;
      initdataa.Textures[0].pObject = 0;
      initdataa.Textures[1].pObject = 0;
      initdataa.pFormat = pVFormat;
      if ( Type == Fill_VColor_TestKey )
        initdataa.SolidColor.Raw = initdata->Color;
      v7 = Scaleform::Render::PrimitiveFillManager::CreateFill(this, &initdataa);
      goto LABEL_4;
    case Fill_Image:
      if ( initdata->Color
        && (v12 = (Scaleform::GFx::Resource *)(*(int (__thiscall **)(unsigned int, Scaleform::Render::TextureManager *))(*(_DWORD *)initdata->Color + 96))(
                                                initdata->Color,
                                                mng)) != 0 )
      {
        Scaleform::Render::PrimitiveFillData::PrimitiveFillData(
          &v21,
          initdata->PrimFill,
          initdata->pVFormat,
          v12,
          initdata->FillMode,
          0,
          0);
        v13 = Scaleform::Render::PrimitiveFillManager::CreateFill(this, &v21);
        Scaleform::Render::PrimitiveFillData::~PrimitiveFillData(&v21);
        result = v13;
      }
      else
      {
        initdataa.Type = PrimFill_SolidColor;
        initdataa.SolidColor.Raw = -65536;
LABEL_3:
        initdataa.pFormat = initdata->pVFormat;
        initdataa.Textures[1].pObject = 0;
        initdataa.Textures[0].pObject = 0;
        initdataa.FillModes[1].Fill = 0;
        initdataa.FillModes[0].Fill = 0;
        v7 = Scaleform::Render::PrimitiveFillManager::CreateFill(this, &initdataa);
LABEL_4:
        v8 = v7;
        Scaleform::Render::PrimitiveFillData::~PrimitiveFillData(&initdataa);
        result = v8;
      }
      break;
    case Fill_Gradient:
      Instance = Scaleform::AmpServer::GetInstance();
      v15 = Instance->GetDisplayStats(Instance);
      Scaleform::AmpFunctionTimer::AmpFunctionTimer(
        (Scaleform::AmpFunctionTimer *)&initdataa,
        v15,
        "PrimitiveFillManager::CreateFill",
        Amp_Profile_Level_Low,
        Amp_Native_Function_Id_GradientFill);
      GradientImage = Scaleform::Render::PrimitiveFillManager::createGradientImage(this, initdata->Color, morphRatio);
      if ( gradientImg->pObject )
        gradientImg->pObject->Release(gradientImg->pObject);
      gradientImg->pObject = GradientImage;
      if ( GradientImage )
      {
        Fill = initdata->FillMode.Fill;
        v17 = (Scaleform::GFx::Resource *)GradientImage->GetTexture(GradientImage, mng);
        Scaleform::Render::PrimitiveFillData::PrimitiveFillData(
          &v21,
          initdata->PrimFill,
          initdata->pVFormat,
          v17,
          (Scaleform::Render::ImageFillMode)Fill,
          0,
          0);
        v18 = Scaleform::Render::PrimitiveFillManager::CreateFill(this, &v21);
        Scaleform::Render::PrimitiveFillData::~PrimitiveFillData(&v21);
        Scaleform::AmpFunctionTimer::~AmpFunctionTimer((Scaleform::AmpFunctionTimer *)&initdataa);
        result = v18;
      }
      else
      {
        Scaleform::AmpFunctionTimer::~AmpFunctionTimer((Scaleform::AmpFunctionTimer *)&initdataa);
LABEL_17:
        result = 0;
      }
      break;
    default:
      goto LABEL_17;
  }
  return result;
}
