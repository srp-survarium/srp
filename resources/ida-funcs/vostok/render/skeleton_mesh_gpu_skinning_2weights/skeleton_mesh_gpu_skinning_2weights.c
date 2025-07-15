void __usercall vostok::render::skeleton_mesh_gpu_skinning_2weights::skeleton_mesh_gpu_skinning_2weights(
        vostok::render::skeleton_mesh_gpu_skinning_2weights *this@<ecx>,
        D3D11_TEXTURE3D_DESC **a2@<esi>)
{
  vostok::render::render_surface::render_surface(this, (int)a2);
  a2[1] = (D3D11_TEXTURE3D_DESC *)3;
  *a2 = &stru_966A14.m_desc_3d;
  a2[39] = 0;
}
