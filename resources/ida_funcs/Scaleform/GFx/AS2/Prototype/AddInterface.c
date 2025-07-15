void __thiscall Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::BitmapData,Scaleform::GFx::AS2::Environment>::AddInterface(
        Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::XmlNodeObject,Scaleform::GFx::AS2::Environment> *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        unsigned int index,
        Scaleform::GFx::AS2::FunctionObject *ctor)
{
  Scaleform::GFx::AS2::GASPrototypeBase::AddInterface(
    (Scaleform::GFx::AS2::GASPrototypeBase *)&this->pWatchpoints,
    psc,
    index,
    ctor);
}


void __thiscall Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::BooleanObject,Scaleform::GFx::AS2::Environment>::AddInterface(
        Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::BevelFilterObject,Scaleform::GFx::AS2::Environment> *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        unsigned int index,
        Scaleform::GFx::AS2::FunctionObject *ctor)
{
  Scaleform::GFx::AS2::GASPrototypeBase::AddInterface(
    (Scaleform::GFx::AS2::GASPrototypeBase *)&this->ResolveHandler.Flags,
    psc,
    index,
    ctor);
}


void __thiscall Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ColorTransformObject,Scaleform::GFx::AS2::Environment>::AddInterface(
        Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ColorTransformObject,Scaleform::GFx::AS2::Environment> *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        unsigned int index,
        Scaleform::GFx::AS2::FunctionObject *ctor)
{
  Scaleform::GFx::AS2::GASPrototypeBase::AddInterface(
    (Scaleform::GFx::AS2::GASPrototypeBase *)this->mColorTransform.M[1],
    psc,
    index,
    ctor);
}


void __thiscall Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::DateObject,Scaleform::GFx::AS2::Environment>::AddInterface(
        Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::DateObject,Scaleform::GFx::AS2::Environment> *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        unsigned int index,
        Scaleform::GFx::AS2::FunctionObject *ctor)
{
  Scaleform::GFx::AS2::GASPrototypeBase::AddInterface(
    (Scaleform::GFx::AS2::GASPrototypeBase *)&this->LTime,
    psc,
    index,
    ctor);
}


void __thiscall Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::LoadVarsObject,Scaleform::GFx::AS2::Environment>::AddInterface(
        Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::NumberObject,Scaleform::GFx::AS2::Environment> *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        unsigned int index,
        Scaleform::GFx::AS2::FunctionObject *ctor)
{
  Scaleform::GFx::AS2::GASPrototypeBase::AddInterface(
    (Scaleform::GFx::AS2::GASPrototypeBase *)&this->mValue,
    psc,
    index,
    ctor);
}


void __thiscall Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::StageObject,Scaleform::GFx::AS2::Environment>::AddInterface(
        Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::GASIme,Scaleform::GFx::AS2::Environment> *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        unsigned int index,
        Scaleform::GFx::AS2::FunctionObject *ctor)
{
  Scaleform::GFx::AS2::GASPrototypeBase::AddInterface(
    (Scaleform::GFx::AS2::GASPrototypeBase *)&this->ResolveHandler.pLocalFrame,
    psc,
    index,
    ctor);
}


void __thiscall Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::StyleSheetObject,Scaleform::GFx::AS2::Environment>::AddInterface(
        Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::StyleSheetObject,Scaleform::GFx::AS2::Environment> *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        unsigned int index,
        Scaleform::GFx::AS2::FunctionObject *ctor)
{
  Scaleform::GFx::AS2::GASPrototypeBase::AddInterface(
    (Scaleform::GFx::AS2::GASPrototypeBase *)&this->CSS.TempKey,
    psc,
    index,
    ctor);
}


void __thiscall Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::TextFormatObject,Scaleform::GFx::AS2::Environment>::AddInterface(
        Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::TextFormatObject,Scaleform::GFx::AS2::Environment> *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        unsigned int index,
        Scaleform::GFx::AS2::FunctionObject *ctor)
{
  Scaleform::GFx::AS2::GASPrototypeBase::AddInterface(
    (Scaleform::GFx::AS2::GASPrototypeBase *)&this->mParagraphFormat.pTabStops,
    psc,
    index,
    ctor);
}


void __thiscall Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::XmlObject,Scaleform::GFx::AS2::Environment>::AddInterface(
        Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::XmlObject,Scaleform::GFx::AS2::Environment> *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        unsigned int index,
        Scaleform::GFx::AS2::FunctionObject *ctor)
{
  Scaleform::GFx::AS2::GASPrototypeBase::AddInterface(
    (Scaleform::GFx::AS2::GASPrototypeBase *)&this->BytesLoadedCurrent,
    psc,
    index,
    ctor);
}
