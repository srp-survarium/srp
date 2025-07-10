void (__cdecl *__usercall btSoftBody::getSolver@<eax>(btSoftBody::eVSolver::_ solver@<eax>))(btSoftBody *, float)
{
  return solver == Linear ? btSoftBody::VSolve_Links : 0;
}
