Scaleform::GFx::MovieDefImpl *__thiscall Scaleform::GFx::AS3::ASVM::GetResourceMovieDef(
        Scaleform::GFx::AS3::ASVM *this,
        Scaleform::GFx::AS3::Instances::fl::Object *instance)
{
  Scaleform::GFx::AS3::Traits *pObject; // esi
  int v4; // eax

  pObject = instance->pTraits.pObject;
  if ( !pObject->pConstructor.pObject )
    pObject->InitOnDemand(instance->pTraits.pObject);
  v4 = (int)pObject->pConstructor.pObject->pTraits.pObject->GetFilePtr(pObject->pConstructor.pObject->pTraits.pObject);
  if ( v4 )
    return *(Scaleform::GFx::MovieDefImpl **)(*(_DWORD *)(v4 + 60) + 192);
  else
    return this->pMovieRoot->pMovieImpl->pMainMovieDef.pObject;
}
