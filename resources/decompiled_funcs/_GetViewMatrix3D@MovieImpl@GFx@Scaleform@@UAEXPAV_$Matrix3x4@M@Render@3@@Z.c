void __thiscall Scaleform::GFx::MovieImpl::GetViewMatrix3D(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::Render::Matrix3x4<float> *viewMat)
{
  Scaleform::GFx::DisplayObjContainer *v2; // eax

  v2 = this->pASMovieRoot.pObject->GetRootMovie(this->pASMovieRoot.pObject, 0);
  if ( v2 )
    v2->GetViewMatrix3D(v2, viewMat, 0);
}
