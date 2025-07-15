void __thiscall Scaleform::GFx::MovieImpl::SetProjectionMatrix3D(
        Scaleform::GFx::MovieImpl *this,
        const Scaleform::Render::Matrix4x4<float> *projMat)
{
  Scaleform::GFx::DisplayObjContainer *v2; // eax

  v2 = this->pASMovieRoot.pObject->GetRootMovie(this->pASMovieRoot.pObject, 0);
  if ( v2 )
    v2->SetProjectionMatrix3D(v2, projMat);
}
