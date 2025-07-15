void __thiscall stlp_std::priv::_Impl_vector<char,stlp_std::allocator<char>>::resize(
        stlp_std::priv::_Impl_vector<char,stlp_std::allocator<char> > *this,
        unsigned int __new_size,
        const char *__x)
{
  if ( __new_size >= this->_M_finish - this->_M_start )
    stlp_std::priv::_Impl_vector<char,stlp_std::allocator<char>>::_M_fill_insert(
      this,
      this->_M_finish,
      __new_size - (this->_M_finish - this->_M_start),
      __x);
  else
    stlp_std::priv::_Impl_vector<char,stlp_std::allocator<char>>::erase(
      this,
      &this->_M_start[__new_size],
      this->_M_finish);
}


void __userpurge stlp_std::priv::_Impl_vector<unsigned short,vostok::render::std_allocator<unsigned short>>::resize(
        stlp_std::priv::_Impl_vector<unsigned short,vostok::render::std_allocator<unsigned short> > *this@<eax>,
        unsigned int __new_size@<edx>,
        unsigned __int16 *__x)
{
  unsigned __int16 *M_finish; // eax
  unsigned int v5; // ecx
  unsigned __int16 *v6; // ecx
  const stlp_std::__true_type *v7; // edx
  unsigned int v8; // ecx
  bool v9; // [esp+0h] [ebp-Ch]

  M_finish = this->_M_finish;
  v5 = M_finish - this->_M_start;
  if ( __new_size >= v5 )
  {
    v7 = (const stlp_std::__true_type *)(__new_size - v5);
    if ( v7 )
    {
      v8 = this->_M_end_of_storage._M_data - M_finish;
      if ( v8 < (unsigned int)v7 )
        stlp_std::priv::_Impl_vector<unsigned short,vostok::render::std_allocator<unsigned short>>::_M_insert_overflow(
          (stlp_std::priv::_Impl_vector<unsigned short,vostok::render::std_allocator<unsigned short> > *)v8,
          M_finish,
          __x,
          v7,
          0,
          v9);
      else
        stlp_std::priv::_Impl_vector<unsigned short,vostok::vectora_allocator<unsigned short>>::_M_fill_insert_aux(
          this,
          M_finish,
          (unsigned int)v7,
          __x,
          (const stlp_std::__false_type *)&__x);
    }
  }
  else
  {
    v6 = &this->_M_start[__new_size];
    if ( v6 != M_finish )
      this->_M_finish = v6;
  }
}


void __userpurge stlp_std::priv::_Impl_vector<unsigned short,vostok::vectora_allocator<unsigned short>>::resize(
        stlp_std::priv::_Impl_vector<unsigned short,vostok::vectora_allocator<unsigned short> > *this@<eax>,
        unsigned int __new_size@<edx>,
        const unsigned __int16 *__x)
{
  unsigned __int16 *M_finish; // eax
  unsigned int v5; // ecx
  unsigned __int16 *v6; // ecx
  const stlp_std::__true_type *v7; // edx
  unsigned int v8; // ecx
  unsigned int v9; // [esp+0h] [ebp-Ch]
  bool v10; // [esp+4h] [ebp-8h]

  M_finish = this->_M_finish;
  v5 = M_finish - this->_M_start;
  if ( __new_size >= v5 )
  {
    v7 = (const stlp_std::__true_type *)(__new_size - v5);
    if ( v7 )
    {
      v8 = this->_M_end_of_storage._M_data - M_finish;
      if ( v8 < (unsigned int)v7 )
        stlp_std::priv::_Impl_vector<unsigned short,vostok::vectora_allocator<unsigned short>>::_M_insert_overflow(
          (stlp_std::priv::_Impl_vector<unsigned short,vostok::vectora_allocator<unsigned short> > *)v8,
          M_finish,
          __x,
          v7,
          v9,
          v10);
      else
        stlp_std::priv::_Impl_vector<unsigned short,vostok::vectora_allocator<unsigned short>>::_M_fill_insert_aux(
          (stlp_std::priv::_Impl_vector<unsigned short,vostok::render::std_allocator<unsigned short> > *)this,
          M_finish,
          (unsigned int)v7,
          __x,
          (const stlp_std::__false_type *)&__x);
    }
  }
  else
  {
    v6 = &this->_M_start[__new_size];
    if ( v6 != M_finish )
      this->_M_finish = v6;
  }
}


void __thiscall stlp_std::priv::_Impl_vector<unsigned int,vostok::ai::std_allocator<unsigned int>>::resize(
        stlp_std::priv::_Impl_vector<unsigned int,vostok::ai::std_allocator<unsigned int> > *this,
        unsigned int __new_size,
        const unsigned int *__x)
{
  if ( __new_size >= this->_M_finish - this->_M_start )
    stlp_std::priv::_Impl_vector<unsigned int,vostok::ai::std_allocator<unsigned int>>::_M_fill_insert(
      this,
      this->_M_finish,
      __new_size - (this->_M_finish - this->_M_start),
      __x);
  else
    stlp_std::priv::_Impl_vector<unsigned int,vostok::ai::std_allocator<unsigned int>>::erase(
      this,
      &this->_M_start[__new_size],
      this->_M_finish);
}


void __userpurge stlp_std::priv::_Impl_vector<unsigned int,survarium::std_allocator<unsigned int>>::resize(
        stlp_std::priv::_Impl_vector<unsigned int,survarium::std_allocator<unsigned int> > *this@<eax>,
        unsigned int __new_size@<edx>,
        const unsigned int *__x)
{
  unsigned int *M_finish; // eax
  unsigned int v5; // ecx
  unsigned int *v6; // ecx
  const stlp_std::__true_type *v7; // edx
  unsigned int v8; // ecx
  unsigned int v9; // [esp+0h] [ebp-Ch]
  bool v10; // [esp+4h] [ebp-8h]

  M_finish = this->_M_finish;
  v5 = M_finish - this->_M_start;
  if ( __new_size >= v5 )
  {
    v7 = (const stlp_std::__true_type *)(__new_size - v5);
    if ( v7 )
    {
      v8 = this->_M_end_of_storage._M_data - M_finish;
      if ( v8 < (unsigned int)v7 )
        stlp_std::priv::_Impl_vector<unsigned int,survarium::std_allocator<unsigned int>>::_M_insert_overflow(
          (stlp_std::priv::_Impl_vector<unsigned int,survarium::std_allocator<unsigned int> > *)v8,
          M_finish,
          __x,
          v7,
          v9,
          v10);
      else
        stlp_std::priv::_Impl_vector<unsigned int,survarium::std_allocator<unsigned int>>::_M_fill_insert_aux(
          this,
          M_finish,
          (unsigned int)v7,
          __x,
          (const stlp_std::__false_type *)&__x);
    }
  }
  else
  {
    v6 = &this->_M_start[__new_size];
    if ( v6 != M_finish )
      this->_M_finish = v6;
  }
}


void __thiscall stlp_std::priv::_Impl_vector<float,vostok::vectora_allocator<float>>::resize(
        stlp_std::priv::_Impl_vector<float,vostok::vectora_allocator<float> > *this,
        unsigned int __new_size,
        const float *__x)
{
  stlp_std::__false_type __formal; // [esp+2Bh] [ebp-9h] BYREF
  float *M_start; // [esp+2Ch] [ebp-8h]
  vostok::sound::search::vertex_id_type *__last; // [esp+30h] [ebp-4h]

  if ( __new_size >= this->_M_finish - this->_M_start )
  {
    stlp_std::priv::_Impl_vector<float,vostok::vectora_allocator<float>>::_M_fill_insert(
      this,
      this->_M_finish,
      __new_size - (this->_M_finish - this->_M_start),
      __x);
  }
  else
  {
    __last = (vostok::sound::search::vertex_id_type *)this->_M_finish;
    M_start = this->_M_start;
    if ( &M_start[__new_size] != (float *)__last )
    {
      __formal = 0;
      stlp_std::priv::_Impl_vector<vostok::sound::search::vertex_id_type,vostok::sound::std_allocator<vostok::sound::search::vertex_id_type>>::_M_erase(
        (stlp_std::priv::_Impl_vector<vostok::sound::search::vertex_id_type,vostok::sound::std_allocator<vostok::sound::search::vertex_id_type> > *)this,
        (vostok::sound::search::vertex_id_type *)&M_start[__new_size],
        __last,
        &__formal);
    }
  }
}


void __userpurge stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::resize(
        stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *this@<eax>,
        unsigned int __new_size@<edx>,
        void *const *__x)
{
  void **M_finish; // eax
  unsigned int v5; // ecx
  void **v6; // ecx
  void **v7; // esi
  const stlp_std::__true_type *v8; // edx
  unsigned int v9; // ecx
  bool v10; // [esp+0h] [ebp-Ch]

  M_finish = this->_M_finish;
  v5 = M_finish - this->_M_start;
  if ( __new_size >= v5 )
  {
    v8 = (const stlp_std::__true_type *)(__new_size - v5);
    if ( v8 )
    {
      v9 = this->_M_end_of_storage._M_data - M_finish;
      if ( v9 < (unsigned int)v8 )
        stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::_M_insert_overflow(
          (stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *)v9,
          (int)this,
          M_finish,
          __x,
          v8,
          0,
          v10);
      else
        stlp_std::priv::_Impl_vector<void *,vostok::input::std_allocator<void *>>::_M_fill_insert_aux(
          (stlp_std::priv::_Impl_vector<void *,vostok::input::std_allocator<void *> > *)this,
          M_finish,
          (unsigned int)v8,
          __x,
          (const stlp_std::__false_type *)&__x);
    }
  }
  else
  {
    v6 = &this->_M_start[__new_size];
    if ( v6 != M_finish )
    {
      LOBYTE(__x) = 0;
      v7 = stlp_std::priv::__copy_ptrs<void * *,void * *>(M_finish, M_finish, v6);
      stlp_std::_Destroy<vostok::fs_new::virtual_path_string>(v7, this->_M_finish);
      this->_M_finish = v7;
    }
  }
}


void __thiscall stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *>>::resize(
        stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *> > *this,
        unsigned int __new_size,
        void *const *__x)
{
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v3; // ecx
  void **v4; // esi
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v5; // ecx
  const vostok::variant<32> **v6; // eax
  void **v7; // eax
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *__n; // [esp+Ch] [ebp-24h]

  if ( __new_size >= stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::size(this) )
  {
    __n = (stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *)(__new_size - stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::size(this));
    v7 = (void **)stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
                    __n,
                    (int)this);
    stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *>>::_M_fill_insert(
      this,
      v7,
      (unsigned int)__n,
      __x);
  }
  else
  {
    v4 = (void **)stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
                    v3,
                    (int)this);
    v6 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v5, (int)this);
    stlp_std::vector<vostok::render::render_surface_instance *,vostok::render::std_allocator<vostok::render::render_surface_instance *>>::erase(
      (void **)&v6[__new_size],
      v4,
      this);
  }
}


void __userpurge stlp_std::priv::_Impl_vector<survarium::account_list_item,vostok::vectora_allocator<survarium::account_list_item>>::resize(
        unsigned int __new_size@<eax>,
        stlp_std::priv::_Impl_vector<survarium::account_list_item,vostok::vectora_allocator<survarium::account_list_item> > *this,
        const survarium::account_list_item *__x)
{
  survarium::account_list_item *M_finish; // edi
  int v4; // ecx
  survarium::account_list_item *v5; // esi
  const stlp_std::random_access_iterator_tag *v6; // [esp+0h] [ebp-10h]
  int *v7; // [esp+4h] [ebp-Ch]

  M_finish = this->_M_finish;
  v4 = (char *)M_finish - (char *)this->_M_start;
  if ( __new_size >= v4 / 52 )
  {
    stlp_std::priv::_Impl_vector<survarium::account_list_item,vostok::vectora_allocator<survarium::account_list_item>>::insert(
      this,
      this->_M_finish,
      __new_size - v4 / 52,
      __x);
  }
  else
  {
    v5 = &this->_M_start[__new_size];
    if ( v5 != M_finish )
      this->_M_finish = stlp_std::priv::__copy<survarium::account_list_item *,survarium::account_list_item *,int>(
                          M_finish,
                          M_finish,
                          v5,
                          v6,
                          v7);
  }
}


void __userpurge stlp_std::priv::_Impl_vector<vostok::render::batched_vertex_source,vostok::render::std_allocator<vostok::render::batched_vertex_source>>::resize(
        unsigned int __new_size@<eax>,
        stlp_std::priv::_Impl_vector<vostok::render::batched_vertex_source,vostok::render::std_allocator<vostok::render::batched_vertex_source> > *this,
        const vostok::render::batched_vertex_source *__x)
{
  unsigned int v4; // eax
  vostok::render::batched_vertex_source *v5; // eax

  v4 = this->_M_finish - this->_M_start;
  if ( __new_size >= v4 )
  {
    stlp_std::priv::_Impl_vector<vostok::render::batched_vertex_source,vostok::render::std_allocator<vostok::render::batched_vertex_source>>::insert(
      this,
      this->_M_finish,
      __new_size - v4,
      __x);
  }
  else
  {
    v5 = &this->_M_start[__new_size];
    if ( v5 != this->_M_finish )
      this->_M_finish = v5;
  }
}


void __userpurge stlp_std::priv::_Impl_vector<vostok::render::branch_vertex,vostok::render::std_allocator<vostok::render::branch_vertex>>::resize(
        unsigned int __new_size@<eax>,
        stlp_std::priv::_Impl_vector<vostok::render::frond_vertex,vostok::render::std_allocator<vostok::render::frond_vertex> > *this,
        const vostok::render::frond_vertex *__x)
{
  vostok::render::frond_vertex *M_finish; // esi
  int v4; // ecx
  vostok::render::frond_vertex *v5; // eax

  M_finish = this->_M_finish;
  v4 = (char *)M_finish - (char *)this->_M_start;
  if ( __new_size >= v4 / 56 )
  {
    stlp_std::priv::_Impl_vector<vostok::render::branch_vertex,vostok::render::std_allocator<vostok::render::branch_vertex>>::_M_fill_insert(
      this,
      M_finish,
      __new_size - v4 / 56,
      __x);
  }
  else
  {
    v5 = &this->_M_start[__new_size];
    if ( v5 != M_finish )
      this->_M_finish = v5;
  }
}


void __userpurge stlp_std::priv::_Impl_vector<D3D11_INPUT_ELEMENT_DESC,vostok::render::std_allocator<D3D11_INPUT_ELEMENT_DESC>>::resize(
        unsigned int __new_size@<eax>,
        stlp_std::priv::_Impl_vector<D3D11_INPUT_ELEMENT_DESC,vostok::render::std_allocator<D3D11_INPUT_ELEMENT_DESC> > *this,
        const D3D11_INPUT_ELEMENT_DESC *__x)
{
  D3D11_INPUT_ELEMENT_DESC *M_finish; // esi
  int v4; // ecx
  D3D11_INPUT_ELEMENT_DESC *v5; // eax

  M_finish = this->_M_finish;
  v4 = (char *)M_finish - (char *)this->_M_start;
  if ( __new_size >= v4 / 28 )
  {
    stlp_std::priv::_Impl_vector<D3D11_INPUT_ELEMENT_DESC,vostok::render::std_allocator<D3D11_INPUT_ELEMENT_DESC>>::_M_fill_insert(
      this,
      M_finish,
      __new_size - v4 / 28,
      __x);
  }
  else
  {
    v5 = &this->_M_start[__new_size];
    if ( v5 != M_finish )
      this->_M_finish = v5;
  }
}


void __userpurge stlp_std::priv::_Impl_vector<survarium::inventory_item_instance,vostok::vectora_allocator<survarium::inventory_item_instance>>::resize(
        stlp_std::priv::_Impl_vector<survarium::inventory_item_instance,vostok::vectora_allocator<survarium::inventory_item_instance> > *this@<eax>,
        unsigned int __new_size@<edx>,
        const survarium::inventory_item_instance *__x)
{
  survarium::inventory_item_instance *M_finish; // eax
  unsigned int v5; // ecx
  survarium::inventory_item_instance *v6; // edx
  const stlp_std::__true_type *v7; // edx
  unsigned int v8; // ecx
  bool v9; // [esp+0h] [ebp-Ch]

  M_finish = this->_M_finish;
  v5 = M_finish - this->_M_start;
  if ( __new_size >= v5 )
  {
    v7 = (const stlp_std::__true_type *)(__new_size - v5);
    if ( v7 )
    {
      v8 = this->_M_end_of_storage._M_data - M_finish;
      if ( v8 < (unsigned int)v7 )
        stlp_std::priv::_Impl_vector<survarium::inventory_item_instance,vostok::vectora_allocator<survarium::inventory_item_instance>>::_M_insert_overflow(
          (stlp_std::priv::_Impl_vector<survarium::inventory_item_instance,vostok::vectora_allocator<survarium::inventory_item_instance> > *)v8,
          M_finish,
          __x,
          v7,
          0,
          v9);
      else
        stlp_std::priv::_Impl_vector<survarium::inventory_item_instance,vostok::vectora_allocator<survarium::inventory_item_instance>>::_M_fill_insert_aux(
          this,
          M_finish,
          (unsigned int)v7,
          __x,
          (const stlp_std::__false_type *)&__x);
    }
  }
  else
  {
    v6 = &this->_M_start[__new_size];
    if ( v6 != M_finish )
      this->_M_finish = v6;
  }
}


void __userpurge stlp_std::priv::_Impl_vector<vostok::render::leafcard_vertex,vostok::render::std_allocator<vostok::render::leafcard_vertex>>::resize(
        unsigned int __new_size@<eax>,
        stlp_std::priv::_Impl_vector<vostok::render::leafcard_vertex,vostok::render::std_allocator<vostok::render::leafcard_vertex> > *this,
        const vostok::render::leafcard_vertex *__x)
{
  vostok::render::leafcard_vertex *M_finish; // esi
  int v4; // ecx
  vostok::render::leafcard_vertex *v5; // eax

  M_finish = this->_M_finish;
  v4 = (char *)M_finish - (char *)this->_M_start;
  if ( __new_size >= v4 / 60 )
  {
    stlp_std::priv::_Impl_vector<vostok::render::leafcard_vertex,vostok::render::std_allocator<vostok::render::leafcard_vertex>>::_M_fill_insert(
      this,
      M_finish,
      __new_size - v4 / 60,
      __x);
  }
  else
  {
    v5 = &this->_M_start[__new_size];
    if ( v5 != M_finish )
      this->_M_finish = v5;
  }
}


void __userpurge stlp_std::priv::_Impl_vector<vostok::render::leafmesh_vertex,vostok::render::std_allocator<vostok::render::leafmesh_vertex>>::resize(
        stlp_std::priv::_Impl_vector<vostok::render::leafmesh_vertex,vostok::render::std_allocator<vostok::render::leafmesh_vertex> > *this@<esi>,
        unsigned int __new_size@<edx>,
        const vostok::render::leafmesh_vertex *__x)
{
  vostok::render::leafmesh_vertex *M_finish; // ecx
  unsigned int v4; // eax
  vostok::render::leafmesh_vertex *v5; // eax
  unsigned int v6; // eax
  bool v7; // [esp+0h] [ebp-8h]

  M_finish = this->_M_finish;
  v4 = M_finish - this->_M_start;
  if ( __new_size >= v4 )
  {
    v6 = __new_size - v4;
    if ( v6 )
    {
      if ( this->_M_end_of_storage._M_data - M_finish < v6 )
        stlp_std::priv::_Impl_vector<vostok::render::leafmesh_vertex,vostok::render::std_allocator<vostok::render::leafmesh_vertex>>::_M_insert_overflow(
          this,
          M_finish,
          __x,
          0,
          v6,
          v7);
      else
        stlp_std::priv::_Impl_vector<vostok::render::leafmesh_vertex,vostok::render::std_allocator<vostok::render::leafmesh_vertex>>::_M_fill_insert_aux(
          this,
          M_finish,
          v6,
          __x,
          (const stlp_std::__false_type *)&__x);
    }
  }
  else
  {
    v5 = &this->_M_start[__new_size];
    if ( v5 != M_finish )
      this->_M_finish = v5;
  }
}


void __userpurge stlp_std::priv::_Impl_vector<vostok::resources::request,survarium::std_allocator<vostok::resources::request>>::resize(
        stlp_std::priv::_Impl_vector<vostok::resources::request,survarium::std_allocator<vostok::resources::request> > *this@<eax>,
        unsigned int __new_size@<edx>,
        const vostok::resources::request *__x)
{
  vostok::resources::request *M_finish; // eax
  unsigned int v5; // ecx
  vostok::resources::request *v6; // ecx
  const stlp_std::__true_type *v7; // edx
  unsigned int v8; // ecx
  bool v9; // [esp+0h] [ebp-10h]

  M_finish = this->_M_finish;
  v5 = M_finish - this->_M_start;
  if ( __new_size >= v5 )
  {
    v7 = (const stlp_std::__true_type *)(__new_size - v5);
    if ( v7 )
    {
      v8 = this->_M_end_of_storage._M_data - M_finish;
      if ( v8 < (unsigned int)v7 )
        stlp_std::priv::_Impl_vector<vostok::resources::request,survarium::std_allocator<vostok::resources::request>>::_M_insert_overflow(
          (stlp_std::priv::_Impl_vector<vostok::resources::request,survarium::std_allocator<vostok::resources::request> > *)v8,
          M_finish,
          __x,
          v7,
          0,
          v9);
      else
        stlp_std::priv::_Impl_vector<vostok::resources::request,survarium::std_allocator<vostok::resources::request>>::_M_fill_insert_aux(
          this,
          M_finish,
          (unsigned int)v7,
          __x,
          (const stlp_std::__false_type *)&__x);
    }
  }
  else
  {
    v6 = &this->_M_start[__new_size];
    if ( v6 != M_finish )
      this->_M_finish = v6;
  }
}


void __userpurge stlp_std::priv::_Impl_vector<vostok::render::ui::vertex,vostok::vectora_allocator<vostok::render::ui::vertex>>::resize(
        unsigned int __new_size@<eax>,
        stlp_std::priv::_Impl_vector<vostok::render::ui::vertex,vostok::vectora_allocator<vostok::render::ui::vertex> > *this,
        const vostok::render::ui::vertex *__x)
{
  vostok::render::ui::vertex *M_finish; // esi
  int v4; // ecx
  vostok::render::ui::vertex *v5; // eax

  M_finish = this->_M_finish;
  v4 = (char *)M_finish - (char *)this->_M_start;
  if ( __new_size >= v4 / 28 )
  {
    stlp_std::priv::_Impl_vector<vostok::render::ui::vertex,vostok::vectora_allocator<vostok::render::ui::vertex>>::_M_fill_insert(
      this,
      M_finish,
      __new_size - v4 / 28,
      __x);
  }
  else
  {
    v5 = &this->_M_start[__new_size];
    if ( v5 != M_finish )
      this->_M_finish = v5;
  }
}


void __thiscall stlp_std::priv::_Impl_vector<vostok::render::vertex_colored,vostok::render::std_allocator<vostok::render::vertex_colored>>::resize(
        stlp_std::priv::_Impl_vector<vostok::render::vertex_colored,vostok::render::std_allocator<vostok::render::vertex_colored> > *this)
{
  vostok::render::vertex_colored *M_finish; // ecx
  vostok::render::vertex_colored *M_start; // edx

  M_finish = this->_M_finish;
  M_start = this->_M_start;
  if ( M_finish - this->_M_start )
  {
    if ( M_start != M_finish )
      this->_M_finish = M_start;
  }
}


void __userpurge stlp_std::priv::_Impl_vector<vostok::render::vertex_colored,vostok::vectora_allocator<vostok::render::vertex_colored>>::resize(
        stlp_std::priv::_Impl_vector<vostok::render::vertex_colored,vostok::vectora_allocator<vostok::render::vertex_colored> > *this@<eax>,
        unsigned int __new_size@<edx>,
        const vostok::render::vertex_colored *__x)
{
  vostok::render::vertex_colored *M_finish; // eax
  unsigned int v5; // ecx
  vostok::render::vertex_colored *v6; // edx
  const stlp_std::__true_type *v7; // edx
  unsigned int v8; // ecx
  unsigned int v9; // [esp+0h] [ebp-Ch]
  bool v10; // [esp+4h] [ebp-8h]

  M_finish = this->_M_finish;
  v5 = M_finish - this->_M_start;
  if ( __new_size >= v5 )
  {
    v7 = (const stlp_std::__true_type *)(__new_size - v5);
    if ( v7 )
    {
      v8 = this->_M_end_of_storage._M_data - M_finish;
      if ( v8 < (unsigned int)v7 )
        stlp_std::priv::_Impl_vector<vostok::render::vertex_colored,vostok::vectora_allocator<vostok::render::vertex_colored>>::_M_insert_overflow(
          (stlp_std::priv::_Impl_vector<vostok::render::vertex_colored,vostok::vectora_allocator<vostok::render::vertex_colored> > *)v8,
          M_finish,
          __x,
          v7,
          v9,
          v10);
      else
        stlp_std::priv::_Impl_vector<vostok::render::vertex_colored,vostok::render::std_allocator<vostok::render::vertex_colored>>::_M_fill_insert_aux(
          (stlp_std::priv::_Impl_vector<vostok::render::vertex_colored,vostok::render::std_allocator<vostok::render::vertex_colored> > *)this,
          M_finish,
          (unsigned int)v7,
          __x,
          (const stlp_std::__false_type *)&__x);
    }
  }
  else
  {
    v6 = &this->_M_start[__new_size];
    if ( v6 != M_finish )
      this->_M_finish = v6;
  }
}


void __thiscall stlp_std::priv::_Impl_vector<vostok::sound::search::vertex_id_type,vostok::sound::std_allocator<vostok::sound::search::vertex_id_type>>::resize(
        stlp_std::priv::_Impl_vector<vostok::sound::search::vertex_id_type,vostok::sound::std_allocator<vostok::sound::search::vertex_id_type> > *this,
        unsigned int __new_size,
        const vostok::sound::search::vertex_id_type *__x)
{
  stlp_std::__false_type __formal; // [esp+2Bh] [ebp-9h] BYREF
  vostok::sound::search::vertex_id_type *M_start; // [esp+2Ch] [ebp-8h]
  vostok::sound::search::vertex_id_type *__last; // [esp+30h] [ebp-4h]

  if ( __new_size >= this->_M_finish - this->_M_start )
  {
    stlp_std::priv::_Impl_vector<vostok::sound::search::vertex_id_type,vostok::sound::std_allocator<vostok::sound::search::vertex_id_type>>::_M_fill_insert(
      this,
      this->_M_finish,
      __new_size - (this->_M_finish - this->_M_start),
      __x);
  }
  else
  {
    __last = this->_M_finish;
    M_start = this->_M_start;
    if ( &M_start[__new_size] != __last )
    {
      __formal = 0;
      stlp_std::priv::_Impl_vector<vostok::sound::search::vertex_id_type,vostok::sound::std_allocator<vostok::sound::search::vertex_id_type>>::_M_erase(
        this,
        &M_start[__new_size],
        __last,
        &__formal);
    }
  }
}


void __thiscall stlp_std::priv::_Impl_vector<survarium::zone_group::zone_wrapper,survarium::std_allocator<survarium::zone_group::zone_wrapper>>::resize(
        stlp_std::priv::_Impl_vector<survarium::zone_group::zone_wrapper,survarium::std_allocator<survarium::zone_group::zone_wrapper> > *this,
        unsigned int __new_size,
        const survarium::zone_group::zone_wrapper *__x)
{
  stlp_std::__false_type __formal; // [esp+2Bh] [ebp-9h] BYREF
  survarium::zone_group::zone_wrapper *M_start; // [esp+2Ch] [ebp-8h]
  vostok::ai::planning::world_state_property *__last; // [esp+30h] [ebp-4h]

  if ( __new_size >= this->_M_finish - this->_M_start )
  {
    stlp_std::priv::_Impl_vector<survarium::zone_group::zone_wrapper,survarium::std_allocator<survarium::zone_group::zone_wrapper>>::_M_fill_insert(
      this,
      this->_M_finish,
      __new_size - (this->_M_finish - this->_M_start),
      __x);
  }
  else
  {
    __last = (vostok::ai::planning::world_state_property *)this->_M_finish;
    M_start = this->_M_start;
    if ( &M_start[__new_size] != (survarium::zone_group::zone_wrapper *)__last )
    {
      __formal = 0;
      stlp_std::priv::_Impl_vector<survarium::hit_receiver_info,survarium::std_allocator<survarium::hit_receiver_info>>::_M_erase(
        (stlp_std::priv::_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property> > *)this,
        (vostok::ai::planning::world_state_property *)&M_start[__new_size],
        __last,
        &__formal);
    }
  }
}


void __userpurge stlp_std::priv::_Impl_vector<vostok::math::float4x4,vostok::render::std_allocator<vostok::math::float4x4>>::resize(
        stlp_std::priv::_Impl_vector<vostok::math::float4x4,vostok::render::std_allocator<vostok::math::float4x4> > *this@<esi>,
        unsigned int __new_size@<edx>,
        const vostok::math::float4x4 *__x)
{
  vostok::math::float4x4 *M_finish; // ecx
  unsigned int v4; // eax
  vostok::math::float4x4 *v5; // eax
  unsigned int v6; // eax
  bool v7; // [esp+0h] [ebp-8h]

  M_finish = this->_M_finish;
  v4 = M_finish - this->_M_start;
  if ( __new_size >= v4 )
  {
    v6 = __new_size - v4;
    if ( v6 )
    {
      if ( this->_M_end_of_storage._M_data - M_finish < v6 )
        stlp_std::priv::_Impl_vector<vostok::render::leafmesh_vertex,vostok::render::std_allocator<vostok::render::leafmesh_vertex>>::_M_insert_overflow(
          (stlp_std::priv::_Impl_vector<vostok::render::leafmesh_vertex,vostok::render::std_allocator<vostok::render::leafmesh_vertex> > *)this,
          (vostok::render::leafmesh_vertex *)M_finish,
          (const vostok::render::leafmesh_vertex *)__x,
          0,
          v6,
          v7);
      else
        stlp_std::priv::_Impl_vector<vostok::math::float4x4,vostok::render::std_allocator<vostok::math::float4x4>>::_M_fill_insert_aux(
          this,
          M_finish,
          v6,
          __x,
          (const stlp_std::__false_type *)&__x);
    }
  }
  else
  {
    v5 = &this->_M_start[__new_size];
    if ( v5 != M_finish )
      this->_M_finish = v5;
  }
}


void __userpurge stlp_std::priv::_Impl_vector<vostok::fixed_string<32>,vostok::render::std_allocator<vostok::fixed_string<32>>>::resize(
        unsigned int __new_size@<eax>,
        stlp_std::priv::_Impl_vector<vostok::fixed_string<32>,vostok::render::std_allocator<vostok::fixed_string<32> > > *this,
        const vostok::fixed_string<32> *__x)
{
  vostok::fixed_string<32> *M_finish; // edi
  int v4; // ecx
  vostok::fixed_string<32> *v5; // ecx
  const stlp_std::random_access_iterator_tag *v6; // [esp+0h] [ebp-10h]
  int *v7; // [esp+4h] [ebp-Ch]

  M_finish = this->_M_finish;
  v4 = (char *)M_finish - (char *)this->_M_start;
  if ( __new_size >= v4 / 44 )
  {
    stlp_std::priv::_Impl_vector<vostok::fixed_string<32>,vostok::render::std_allocator<vostok::fixed_string<32>>>::insert(
      this,
      this->_M_finish,
      __new_size - v4 / 44,
      __x);
  }
  else
  {
    v5 = &this->_M_start[__new_size];
    if ( v5 != M_finish )
      this->_M_finish = stlp_std::priv::__copy<vostok::fixed_string<32> *,vostok::fixed_string<32> *,int>(
                          this->_M_finish,
                          M_finish,
                          v5,
                          v6,
                          v7);
  }
}


void __thiscall stlp_std::priv::_Impl_vector<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>>::resize(
        stlp_std::priv::_Impl_vector<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32> > > *this,
        unsigned int __new_size,
        const vostok::fixed_vector<unsigned int,32> *__x)
{
  stlp_std::__false_type __formal; // [esp+3Bh] [ebp-9h] BYREF
  vostok::fixed_vector<unsigned int,32> *M_start; // [esp+3Ch] [ebp-8h]
  vostok::fixed_vector<unsigned int,32> *__last; // [esp+40h] [ebp-4h]

  if ( __new_size >= this->_M_finish - this->_M_start )
  {
    stlp_std::priv::_Impl_vector<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>>::_M_fill_insert(
      this,
      this->_M_finish,
      __new_size - (this->_M_finish - this->_M_start),
      __x);
  }
  else
  {
    __last = this->_M_finish;
    M_start = this->_M_start;
    if ( &M_start[__new_size] != __last )
    {
      __formal = 0;
      stlp_std::priv::_Impl_vector<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>>::_M_erase(
        this,
        &M_start[__new_size],
        __last,
        &__formal);
    }
  }
}


void __thiscall stlp_std::priv::_Impl_vector<vostok::variant<32>,survarium::std_allocator<vostok::variant<32>>>::resize(
        stlp_std::priv::_Impl_vector<vostok::variant<32>,survarium::std_allocator<vostok::variant<32> > > *this,
        unsigned int __new_size,
        const vostok::variant<32> *__x)
{
  stlp_std::__false_type __formal; // [esp+33h] [ebp-9h] BYREF
  vostok::variant<32> *M_start; // [esp+34h] [ebp-8h]
  vostok::variant<32> *__last; // [esp+38h] [ebp-4h]

  if ( __new_size >= this->_M_finish - this->_M_start )
  {
    stlp_std::priv::_Impl_vector<vostok::variant<32>,survarium::std_allocator<vostok::variant<32>>>::_M_fill_insert(
      this,
      this->_M_finish,
      __new_size - (this->_M_finish - this->_M_start),
      __x);
  }
  else
  {
    __last = this->_M_finish;
    M_start = this->_M_start;
    if ( &M_start[__new_size] != __last )
    {
      __formal = 0;
      stlp_std::priv::_Impl_vector<vostok::variant<32>,survarium::std_allocator<vostok::variant<32>>>::_M_erase(
        this,
        &M_start[__new_size],
        __last,
        &__formal);
    }
  }
}
