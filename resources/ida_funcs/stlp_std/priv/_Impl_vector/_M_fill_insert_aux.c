void __thiscall stlp_std::priv::_Impl_vector<char,stlp_std::allocator<char>>::_M_fill_insert_aux(
        stlp_std::priv::_Impl_vector<char,stlp_std::allocator<char> > *this,
        char *__pos,
        unsigned int __n,
        const char *__x,
        const stlp_std::__false_type *__formal)
{
  int i; // [esp+18h] [ebp-34h]
  char *M_finish; // [esp+1Ch] [ebp-30h]
  char *v9; // [esp+24h] [ebp-28h]
  stlp_std::__false_type v10; // [esp+42h] [ebp-Ah] BYREF
  char __x_copy; // [esp+43h] [ebp-9h] BYREF
  char *__old_finish; // [esp+44h] [ebp-8h]
  unsigned int __elems_after; // [esp+48h] [ebp-4h]

  if ( __x >= this->_M_start && __x < this->_M_finish )
  {
    __x_copy = *__x;
    v10 = 0;
    stlp_std::priv::_Impl_vector<char,stlp_std::allocator<char>>::_M_fill_insert_aux(this, __pos, __n, &__x_copy, &v10);
  }
  else
  {
    __elems_after = this->_M_finish - __pos;
    __old_finish = this->_M_finish;
    if ( __elems_after <= __n )
    {
      v9 = &this->_M_finish[__n - __elems_after];
      M_finish = this->_M_finish;
      for ( i = __n - __elems_after; i > 0; --i )
      {
        survarium::generate_shaders_world::is_loading();
        survarium::generate_shaders_world::is_loading();
        *M_finish++ = *__x;
      }
      this->_M_finish = v9;
      stlp_std::priv::__ucopy_trivial(
        (unsigned __int8 *)__pos,
        (unsigned __int8 *)__old_finish,
        (unsigned __int8 *)this->_M_finish);
      this->_M_finish += __elems_after;
      memset((unsigned __int8 *)__pos, *__x, __old_finish - __pos);
    }
    else
    {
      stlp_std::priv::__ucopy_trivial(
        (unsigned __int8 *)&this->_M_finish[-__n],
        (unsigned __int8 *)this->_M_finish,
        (unsigned __int8 *)this->_M_finish);
      this->_M_finish += __n;
      stlp_std::priv::__copy_trivial_backward((unsigned __int8 *)__pos, &__old_finish[-__n], __old_finish);
      memset((unsigned __int8 *)__pos, *__x, __n);
    }
  }
}


void __thiscall stlp_std::priv::_Impl_vector<unsigned short,vostok::vectora_allocator<unsigned short>>::_M_fill_insert_aux(
        stlp_std::priv::_Impl_vector<unsigned short,vostok::render::std_allocator<unsigned short> > *this,
        unsigned __int16 *__pos,
        unsigned int __n,
        unsigned __int16 *__x,
        const stlp_std::__false_type *__formal)
{
  unsigned __int16 *v6; // ecx
  unsigned __int16 *v7; // ebx
  unsigned __int16 *M_finish; // esi
  unsigned int v9; // edi
  signed int v10; // eax
  int j; // eax
  unsigned __int16 *v12; // edx
  int v13; // eax
  unsigned __int16 *v14; // ecx
  int v15; // esi
  unsigned __int16 *i; // eax
  int __x_copy; // [esp+4h] [ebp-4h] BYREF

  v6 = __x;
  if ( __x < this->_M_start || __x >= this->_M_finish )
  {
    v7 = __pos;
    M_finish = this->_M_finish;
    v9 = M_finish - __pos;
    if ( v9 <= __n )
    {
      v12 = &M_finish[__n - v9];
      v13 = (int)(2 * (__n - v9)) >> 1;
      v14 = this->_M_finish;
      if ( v13 > 0 )
      {
        do
        {
          *v14 = *__x;
          --v13;
          ++v14;
        }
        while ( v13 > 0 );
        v12 = &M_finish[__n - v9];
      }
      this->_M_finish = v12;
      if ( M_finish != __pos )
        memcpy((unsigned __int8 *)v12, (unsigned __int8 *)__pos, (char *)M_finish - (char *)__pos);
      this->_M_finish += v9;
      v15 = M_finish - __pos;
      for ( i = __pos; v15 > 0; ++i )
      {
        *i = *__x;
        --v15;
      }
    }
    else
    {
      v10 = 2 * __n;
      if ( M_finish != &M_finish[-__n] )
      {
        memcpy((unsigned __int8 *)M_finish, (unsigned __int8 *)&M_finish[v10 / 0xFFFFFFFE], v10);
        v10 = 2 * __n;
        v6 = __x;
      }
      this->_M_finish = (unsigned __int16 *)((char *)this->_M_finish + v10);
      if ( (char *)&M_finish[-__n] - (char *)__pos > 0 )
      {
        memmove((unsigned __int8 *)&__pos[__n], (unsigned __int8 *)__pos, (char *)&M_finish[-__n] - (char *)__pos);
        v10 = 2 * __n;
        v6 = __x;
      }
      for ( j = v10 >> 1; j > 0; ++v7 )
      {
        *v7 = *v6;
        --j;
      }
    }
  }
  else
  {
    __x_copy = *__x;
    LOBYTE(__x) = 0;
    stlp_std::priv::_Impl_vector<unsigned short,vostok::vectora_allocator<unsigned short>>::_M_fill_insert_aux(
      this,
      __pos,
      __n,
      (const unsigned __int16 *)&__x_copy,
      (const stlp_std::__false_type *)&__x);
  }
}


void __thiscall stlp_std::priv::_Impl_vector<unsigned int,vostok::ai::std_allocator<unsigned int>>::_M_fill_insert_aux(
        stlp_std::priv::_Impl_vector<unsigned int,vostok::ai::std_allocator<unsigned int> > *this,
        unsigned int *__pos,
        unsigned int __n,
        unsigned int *__x,
        const stlp_std::__false_type *__formal)
{
  stlp_std::__false_type v7; // [esp+37h] [ebp-Dh] BYREF
  unsigned int __x_copy; // [esp+38h] [ebp-Ch] BYREF
  unsigned int *__old_finish; // [esp+3Ch] [ebp-8h]
  unsigned int __elems_after; // [esp+40h] [ebp-4h]

  if ( __x >= this->_M_start && __x < this->_M_finish )
  {
    __x_copy = *__x;
    v7 = 0;
    stlp_std::priv::_Impl_vector<unsigned int,vostok::ai::std_allocator<unsigned int>>::_M_fill_insert_aux(
      this,
      __pos,
      __n,
      &__x_copy,
      &v7);
  }
  else
  {
    __elems_after = this->_M_finish - __pos;
    __old_finish = this->_M_finish;
    if ( __elems_after <= __n )
    {
      this->_M_finish = stlp_std::priv::__uninitialized_fill_n<unsigned int *,unsigned int,unsigned int>(
                          this->_M_finish,
                          __n - __elems_after,
                          __x);
      stlp_std::priv::__ucopy_ptrs<unsigned int *,unsigned int *>(
        (char *)__pos,
        (unsigned __int8 *)this->_M_finish,
        (char *)__old_finish);
      this->_M_finish += __elems_after;
      stlp_std::fill<unsigned int *,unsigned int>(__old_finish, __x, __pos);
    }
    else
    {
      stlp_std::priv::__ucopy_ptrs<unsigned int *,unsigned int *>(
        (char *)&this->_M_finish[-__n],
        (unsigned __int8 *)this->_M_finish,
        (char *)this->_M_finish);
      this->_M_finish += __n;
      stlp_std::priv::__copy_backward_ptrs<unsigned int *,unsigned int *>(
        (char *)&__old_finish[-__n],
        (unsigned __int8 *)__old_finish,
        __pos);
      stlp_std::fill<unsigned int *,unsigned int>(&__pos[__n], __x, __pos);
    }
  }
}


void __thiscall stlp_std::priv::_Impl_vector<unsigned int,survarium::std_allocator<unsigned int>>::_M_fill_insert_aux(
        stlp_std::priv::_Impl_vector<unsigned int,survarium::std_allocator<unsigned int> > *this,
        unsigned int *__pos,
        unsigned int __n,
        unsigned int *__x,
        const stlp_std::__false_type *__formal)
{
  const unsigned int *v6; // ecx
  unsigned int *v7; // ebx
  unsigned int *M_finish; // esi
  unsigned int v9; // edi
  signed int v10; // eax
  int j; // eax
  unsigned int *v12; // edx
  int v13; // eax
  unsigned int *v14; // ecx
  int v15; // esi
  unsigned int *i; // eax
  unsigned int __x_copy; // [esp+4h] [ebp-4h] BYREF

  v6 = __x;
  if ( __x < this->_M_start || __x >= this->_M_finish )
  {
    v7 = __pos;
    M_finish = this->_M_finish;
    v9 = M_finish - __pos;
    if ( v9 <= __n )
    {
      v12 = &M_finish[__n - v9];
      v13 = (int)(4 * (__n - v9)) >> 2;
      v14 = this->_M_finish;
      if ( v13 > 0 )
      {
        do
        {
          *v14 = *__x;
          --v13;
          ++v14;
        }
        while ( v13 > 0 );
        v12 = &M_finish[__n - v9];
      }
      this->_M_finish = v12;
      if ( M_finish != __pos )
        memcpy((unsigned __int8 *)v12, (unsigned __int8 *)__pos, (char *)M_finish - (char *)__pos);
      this->_M_finish += v9;
      v15 = M_finish - __pos;
      for ( i = __pos; v15 > 0; ++i )
      {
        *i = *__x;
        --v15;
      }
    }
    else
    {
      v10 = 4 * __n;
      if ( M_finish != &M_finish[-__n] )
      {
        memcpy((unsigned __int8 *)M_finish, (unsigned __int8 *)&M_finish[v10 / 0xFFFFFFFC], v10);
        v10 = 4 * __n;
        v6 = __x;
      }
      this->_M_finish = (unsigned int *)((char *)this->_M_finish + v10);
      if ( (char *)&M_finish[-__n] - (char *)__pos > 0 )
      {
        memmove((unsigned __int8 *)&__pos[__n], (unsigned __int8 *)__pos, (char *)&M_finish[-__n] - (char *)__pos);
        v10 = 4 * __n;
        v6 = __x;
      }
      for ( j = v10 >> 2; j > 0; ++v7 )
      {
        *v7 = *v6;
        --j;
      }
    }
  }
  else
  {
    __x_copy = *__x;
    LOBYTE(__x) = 0;
    stlp_std::priv::_Impl_vector<unsigned int,survarium::std_allocator<unsigned int>>::_M_fill_insert_aux(
      this,
      __pos,
      __n,
      &__x_copy,
      (const stlp_std::__false_type *)&__x);
  }
}


void __thiscall stlp_std::priv::_Impl_vector<float,vostok::vectora_allocator<float>>::_M_fill_insert_aux(
        stlp_std::priv::_Impl_vector<float,vostok::vectora_allocator<float> > *this,
        float *__pos,
        unsigned int __n,
        float *__x,
        const stlp_std::__false_type *__formal)
{
  float *v7; // [esp+14h] [ebp-50h]
  int i; // [esp+18h] [ebp-4Ch]
  float *v9; // [esp+38h] [ebp-2Ch]
  int j; // [esp+3Ch] [ebp-28h]
  float *M_finish; // [esp+4Ch] [ebp-18h]
  stlp_std::__false_type v12; // [esp+57h] [ebp-Dh] BYREF
  float __x_copy; // [esp+58h] [ebp-Ch] BYREF
  float *__old_finish; // [esp+5Ch] [ebp-8h]
  unsigned int __elems_after; // [esp+60h] [ebp-4h]

  if ( __x >= this->_M_start && __x < this->_M_finish )
  {
    __x_copy = *__x;
    v12 = 0;
    stlp_std::priv::_Impl_vector<float,vostok::vectora_allocator<float>>::_M_fill_insert_aux(
      this,
      __pos,
      __n,
      &__x_copy,
      &v12);
  }
  else
  {
    __elems_after = this->_M_finish - __pos;
    __old_finish = this->_M_finish;
    if ( __elems_after <= __n )
    {
      this->_M_finish = stlp_std::priv::__uninitialized_fill_n<float *,unsigned int,float>(
                          this->_M_finish,
                          __n - __elems_after,
                          __x);
      if ( __old_finish != __pos )
        memcpy((unsigned __int8 *)this->_M_finish, (unsigned __int8 *)__pos, (char *)__old_finish - (char *)__pos);
      this->_M_finish += __elems_after;
      v7 = __pos;
      for ( i = __old_finish - __pos; i > 0; --i )
        *v7++ = *__x;
    }
    else
    {
      M_finish = this->_M_finish;
      if ( M_finish != &M_finish[-__n] )
        memcpy((unsigned __int8 *)this->_M_finish, (unsigned __int8 *)&M_finish[-__n], 4 * __n);
      this->_M_finish += __n;
      if ( (char *)&__old_finish[-__n] - (char *)__pos > 0 )
        memmove((unsigned __int8 *)&__pos[__n], (unsigned __int8 *)__pos, (char *)&__old_finish[-__n] - (char *)__pos);
      v9 = __pos;
      for ( j = (int)(4 * __n) >> 2; j > 0; --j )
        *v9++ = *__x;
    }
  }
}


void __thiscall stlp_std::priv::_Impl_vector<void *,vostok::input::std_allocator<void *>>::_M_fill_insert_aux(
        stlp_std::priv::_Impl_vector<void *,vostok::input::std_allocator<void *> > *this,
        void **__pos,
        unsigned int __n,
        void **__x,
        const stlp_std::__false_type *__formal)
{
  void **M_finish; // esi
  unsigned int v7; // ebx
  void **v8; // ebx
  signed int v9; // ebx
  void **v10; // eax
  void *const *v11; // [esp-2Ch] [ebp-34h]
  void *__x_copy; // [esp+4h] [ebp-4h] BYREF
  unsigned int __na; // [esp+10h] [ebp+8h]

  if ( __x < this->_M_start || __x >= this->_M_finish )
  {
    M_finish = this->_M_finish;
    v7 = M_finish - __pos;
    if ( v7 <= __n )
    {
      v10 = stlp_std::priv::__uninitialized_fill_n<void * *,unsigned int,void *>(M_finish, __n - v7, __x);
      this->_M_finish = v10;
      stlp_std::priv::__ucopy_ptrs<void * *,void * *>(__pos, M_finish, v10);
      v11 = __x;
      this->_M_finish += v7;
      stlp_std::fill<void * *,void *>(__pos, M_finish, v11);
    }
    else
    {
      v8 = &M_finish[-__n];
      __na = __n;
      stlp_std::priv::__ucopy_ptrs<void * *,void * *>(v8, M_finish, M_finish);
      this->_M_finish = (void **)((char *)this->_M_finish + __na * 4);
      v9 = (char *)v8 - (char *)__pos;
      if ( v9 > 0 )
        memmove((unsigned __int8 *)M_finish - v9, (unsigned __int8 *)__pos, v9);
      stlp_std::fill<void * *,void *>(__pos, &__pos[__na], __x);
    }
  }
  else
  {
    __x_copy = *__x;
    LOBYTE(__x) = 0;
    stlp_std::priv::_Impl_vector<void *,vostok::input::std_allocator<void *>>::_M_fill_insert_aux(
      this,
      __pos,
      __n,
      &__x_copy,
      (const stlp_std::__false_type *)&__x);
  }
}


void __thiscall stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *>>::_M_fill_insert_aux(
        stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *> > *this,
        void **__pos,
        unsigned int __n,
        void *const *__x,
        const stlp_std::__false_type *__formal)
{
  void **v7; // [esp+8h] [ebp-50h]
  int i; // [esp+Ch] [ebp-4Ch]
  void **v9; // [esp+2Ch] [ebp-2Ch]
  int j; // [esp+30h] [ebp-28h]
  stlp_std::__false_type v11; // [esp+4Bh] [ebp-Dh] BYREF
  void *__x_copy; // [esp+4Ch] [ebp-Ch] BYREF
  void **__old_finish; // [esp+50h] [ebp-8h]
  unsigned int __elems_after; // [esp+54h] [ebp-4h]

  if ( __x >= this->_M_start && __x < this->_M_finish )
  {
    __x_copy = *__x;
    v11 = 0;
    stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *>>::_M_fill_insert_aux(
      this,
      __pos,
      __n,
      &__x_copy,
      &v11);
  }
  else
  {
    __elems_after = this->_M_finish - __pos;
    __old_finish = this->_M_finish;
    if ( __elems_after <= __n )
    {
      this->_M_finish = stlp_std::priv::__uninitialized_fill_n<void * *,unsigned int,void *>(
                          this->_M_finish,
                          __n - __elems_after,
                          __x);
      stlp_std::priv::__ucopy_trivial(
        (unsigned __int8 *)__pos,
        (unsigned __int8 *)__old_finish,
        (unsigned __int8 *)this->_M_finish);
      this->_M_finish += __elems_after;
      v7 = __pos;
      for ( i = __old_finish - __pos; i > 0; --i )
        *v7++ = *__x;
    }
    else
    {
      stlp_std::priv::__ucopy_trivial(
        (unsigned __int8 *)&this->_M_finish[-__n],
        (unsigned __int8 *)this->_M_finish,
        (unsigned __int8 *)this->_M_finish);
      this->_M_finish += __n;
      stlp_std::priv::__copy_trivial_backward((unsigned __int8 *)__pos, &__old_finish[-__n], (char *)__old_finish);
      v9 = __pos;
      for ( j = (int)(4 * __n) >> 2; j > 0; --j )
        *v9++ = *__x;
    }
  }
}


void __thiscall stlp_std::priv::_Impl_vector<vostok::render::light_data,vostok::render::std_allocator<vostok::render::light_data>>::_M_fill_insert_aux(
        stlp_std::priv::_Impl_vector<vostok::render::light_data,vostok::render::std_allocator<vostok::render::light_data> > *this,
        vostok::render::light_data *__pos,
        unsigned int __n,
        unsigned int __x,
        const stlp_std::__false_type *__formal)
{
  const vostok::render::light_data *v5; // esi
  vostok::render::light *v7; // ecx
  vostok::render::light *m_object; // eax
  vostok::render::grass_render_model *v9; // esi
  vostok::render::light *v10; // ebp
  vostok::render::light_data *M_finish; // edi
  unsigned int v13; // eax
  const stlp_std::random_access_iterator_tag *v14; // [esp+0h] [ebp-1Ch]
  const stlp_std::random_access_iterator_tag *v15; // [esp+0h] [ebp-1Ch]
  const stlp_std::random_access_iterator_tag *v16; // [esp+0h] [ebp-1Ch]
  const stlp_std::random_access_iterator_tag *v17; // [esp+0h] [ebp-1Ch]
  const stlp_std::random_access_iterator_tag *v18; // [esp+0h] [ebp-1Ch]
  int *v19; // [esp+4h] [ebp-18h]
  int *v20; // [esp+4h] [ebp-18h]
  int *v21; // [esp+4h] [ebp-18h]
  int *v22; // [esp+4h] [ebp-18h]
  int *v23; // [esp+4h] [ebp-18h]
  vostok::render::light_data __x_copy; // [esp+10h] [ebp-Ch] BYREF
  vostok::render::light_data *__posa; // [esp+20h] [ebp+4h]
  vostok::render::light_data *__posb; // [esp+20h] [ebp+4h]
  vostok::render::light_data *__na; // [esp+24h] [ebp+8h]

  v5 = (const vostok::render::light_data *)__x;
  if ( (vostok::render::light_data *)__x < this->_M_start || (vostok::render::light_data *)__x >= this->_M_finish )
  {
    M_finish = this->_M_finish;
    v13 = M_finish - __pos;
    __x = v13;
    if ( v13 <= __n )
    {
      __posb = &M_finish[__n - v13];
      stlp_std::priv::__ufill<vostok::render::light_data *,vostok::render::light_data,int>(
        M_finish,
        __posb,
        v5,
        v14,
        v19);
      this->_M_finish = __posb;
      stlp_std::priv::__ucopy<vostok::render::light_data *,vostok::render::light_data *,int>(
        __pos,
        M_finish,
        __posb,
        v17,
        v22);
      this->_M_finish += __x;
      stlp_std::priv::__fill<vostok::render::light_data *,vostok::render::light_data,int>(__pos, M_finish, v5, v18, v23);
    }
    else
    {
      __posa = (vostok::render::light_data *)(8 * __n);
      __na = &M_finish[-__n];
      stlp_std::priv::__ucopy<vostok::render::light_data *,vostok::render::light_data *,int>(
        __na,
        M_finish,
        M_finish,
        v14,
        v19);
      this->_M_finish = (vostok::render::light_data *)((char *)this->_M_finish + (unsigned int)__posa);
      stlp_std::priv::__copy_backward<vostok::render::light_data *,vostok::render::light_data *,int>(
        __pos,
        __na,
        M_finish,
        v15,
        v20);
      stlp_std::priv::__fill<vostok::render::light_data *,vostok::render::light_data,int>(
        __pos,
        (vostok::render::light_data *)((char *)__pos + (_DWORD)__posa),
        v5,
        v16,
        v21);
    }
  }
  else
  {
    __x_copy.light.m_object = 0;
    vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
      (vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)this,
      &__x_copy.light,
      (const vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)__x);
    __x_copy.id = v5->id;
    LOBYTE(__x) = 0;
    stlp_std::priv::_Impl_vector<vostok::render::light_data,vostok::render::std_allocator<vostok::render::light_data>>::_M_fill_insert_aux(
      this,
      __pos,
      __n,
      &__x_copy,
      (const stlp_std::__false_type *)&__x);
    m_object = __x_copy.light.m_object;
    if ( __x_copy.light.m_object )
    {
      --__x_copy.light.m_object->m_reference_count;
      if ( !m_object->m_reference_count )
      {
        v9 = vostok::render::g_allocator.m_object;
        v10 = __x_copy.light.m_object;
        if ( __x_copy.light.m_object )
        {
          vostok::render::light::~light(v7);
          BYTE2(v9->m_children_resources.m_lock) = 0;
          vostok_mspace_free((void *)HIDWORD(v9->m_reconstruction_info_actuality_tick), v10);
        }
      }
    }
  }
}


void __userpurge stlp_std::priv::_Impl_vector<vostok::render::ui::vertex,vostok::vectora_allocator<vostok::render::ui::vertex>>::_M_fill_insert_aux(
        stlp_std::priv::_Impl_vector<vostok::render::ui::vertex,vostok::vectora_allocator<vostok::render::ui::vertex> > *this@<ecx>,
        int *a2@<ebx>,
        const stlp_std::random_access_iterator_tag *a3@<edi>,
        vostok::render::ui::vertex *__pos,
        unsigned int __n,
        const vostok::render::ui::vertex *__x,
        const stlp_std::__false_type *__formal)
{
  const D3D11_INPUT_ELEMENT_DESC *v7; // esi
  unsigned int m_color; // eax
  __int64 v10; // xmm0_8
  vostok::render::ui::vertex *M_finish; // edi
  unsigned int v12; // ebx
  const stlp_std::random_access_iterator_tag *v14; // [esp-8h] [ebp-2Ch]
  const stlp_std::random_access_iterator_tag *v15; // [esp-8h] [ebp-2Ch]
  const stlp_std::random_access_iterator_tag *v16; // [esp-8h] [ebp-2Ch]
  int *v18; // [esp-4h] [ebp-28h]
  int *v19; // [esp-4h] [ebp-28h]
  int *v20; // [esp-4h] [ebp-28h]
  vostok::render::ui::vertex __x_copy; // [esp+8h] [ebp-1Ch] BYREF
  vostok::render::ui::vertex *__na; // [esp+2Ch] [ebp+8h]

  v7 = (const D3D11_INPUT_ELEMENT_DESC *)__x;
  if ( __x < this->_M_start || __x >= this->_M_finish )
  {
    M_finish = this->_M_finish;
    v12 = M_finish - __pos;
    if ( v12 <= __n )
    {
      __na = &M_finish[__n - v12];
      stlp_std::priv::__ufill<vostok::render::ui::vertex *,vostok::render::ui::vertex,int>(M_finish, __na, __x, a3, a2);
      this->_M_finish = __na;
      stlp_std::priv::__ucopy<vostok::render::ui::vertex *,vostok::render::ui::vertex *,int>(
        __pos,
        M_finish,
        __na,
        v15,
        v19);
      this->_M_finish += v12;
      stlp_std::priv::__fill<D3D11_INPUT_ELEMENT_DESC *,D3D11_INPUT_ELEMENT_DESC,int>(
        (D3D11_INPUT_ELEMENT_DESC *)__pos,
        (D3D11_INPUT_ELEMENT_DESC *)M_finish,
        v7,
        v16,
        v20);
    }
    else
    {
      stlp_std::priv::__ucopy<vostok::render::ui::vertex *,vostok::render::ui::vertex *,int>(
        &M_finish[-__n],
        M_finish,
        M_finish,
        a3,
        a2);
      this->_M_finish += __n;
      if ( (char *)&M_finish[-__n] - (char *)__pos > 0 )
        memmove((unsigned __int8 *)&__pos[__n], (unsigned __int8 *)__pos, (char *)&M_finish[-__n] - (char *)__pos);
      stlp_std::priv::__fill<D3D11_INPUT_ELEMENT_DESC *,D3D11_INPUT_ELEMENT_DESC,int>(
        (D3D11_INPUT_ELEMENT_DESC *)__pos,
        (D3D11_INPUT_ELEMENT_DESC *)&__pos[__n],
        (const D3D11_INPUT_ELEMENT_DESC *)__x,
        v14,
        v18);
    }
  }
  else
  {
    m_color = __x->m_color;
    *(_QWORD *)&__x_copy.m_position.x = *(_QWORD *)&__x->m_position.x;
    v10 = *(_QWORD *)&__x->m_position.elements[2];
    __x_copy.m_color = m_color;
    *(_QWORD *)&__x_copy.m_position.elements[2] = v10;
    __x_copy.m_uv = __x->m_uv;
    LOBYTE(__x) = 0;
    stlp_std::priv::_Impl_vector<vostok::render::ui::vertex,vostok::vectora_allocator<vostok::render::ui::vertex>>::_M_fill_insert_aux(
      this,
      __pos,
      __n,
      &__x_copy,
      (const stlp_std::__false_type *)&__x);
  }
}


void __thiscall stlp_std::priv::_Impl_vector<vostok::math::float4x4,vostok::render::std_allocator<vostok::math::float4x4>>::_M_fill_insert_aux(
        stlp_std::priv::_Impl_vector<vostok::math::float4x4,vostok::render::std_allocator<vostok::math::float4x4> > *this,
        vostok::math::float4x4 *__pos,
        unsigned int __n,
        const vostok::math::float4x4 *__x,
        const stlp_std::__false_type *__formal)
{
  const vostok::render::leafmesh_vertex *v5; // edx
  vostok::math::float4x4 *M_finish; // edi
  unsigned int v8; // ebx
  unsigned int v9; // eax
  vostok::math::float4x4 *v10; // eax
  const vostok::render::leafmesh_vertex *v11; // [esp-4h] [ebp-58h]
  vostok::math::float4x4 __x_copy; // [esp+10h] [ebp-44h] BYREF

  v5 = (const vostok::render::leafmesh_vertex *)__x;
  if ( __x < this->_M_start || __x >= this->_M_finish )
  {
    M_finish = this->_M_finish;
    v8 = M_finish - __pos;
    if ( v8 <= __n )
    {
      v10 = stlp_std::priv::__uninitialized_fill_n<vostok::math::float4x4 *,unsigned int,vostok::math::float4x4>(
              M_finish,
              __n - v8,
              __x);
      this->_M_finish = v10;
      if ( M_finish != __pos )
        memcpy((unsigned __int8 *)v10, (unsigned __int8 *)__pos, (char *)M_finish - (char *)__pos);
      v11 = (const vostok::render::leafmesh_vertex *)__x;
      this->_M_finish += v8;
      stlp_std::fill<vostok::render::leafmesh_vertex *,vostok::render::leafmesh_vertex>(
        (vostok::render::leafmesh_vertex *)__pos,
        (vostok::render::leafmesh_vertex *)M_finish,
        v11);
    }
    else
    {
      v9 = __n << 6;
      if ( M_finish != &M_finish[-__n] )
      {
        memcpy((unsigned __int8 *)M_finish, (unsigned __int8 *)M_finish - v9, v9);
        v5 = (const vostok::render::leafmesh_vertex *)__x;
        v9 = __n << 6;
      }
      this->_M_finish = (vostok::math::float4x4 *)((char *)this->_M_finish + v9);
      if ( (char *)&M_finish[-__n] - (char *)__pos > 0 )
      {
        memmove((unsigned __int8 *)&__pos[__n], (unsigned __int8 *)__pos, (char *)&M_finish[-__n] - (char *)__pos);
        v5 = (const vostok::render::leafmesh_vertex *)__x;
        v9 = __n << 6;
      }
      stlp_std::fill<vostok::render::leafmesh_vertex *,vostok::render::leafmesh_vertex>(
        (vostok::render::leafmesh_vertex *)__pos,
        (vostok::render::leafmesh_vertex *)((char *)__pos + v9),
        v5);
    }
  }
  else
  {
    qmemcpy((void *)&__x_copy, __x, sizeof(__x_copy));
    LOBYTE(__x) = 0;
    stlp_std::priv::_Impl_vector<vostok::math::float4x4,vostok::render::std_allocator<vostok::math::float4x4>>::_M_fill_insert_aux(
      this,
      __pos,
      __n,
      &__x_copy,
      (const stlp_std::__false_type *)&__x);
  }
}


void __thiscall stlp_std::priv::_Impl_vector<vostok::variant<32>,survarium::std_allocator<vostok::variant<32>>>::_M_fill_insert_aux(
        stlp_std::priv::_Impl_vector<vostok::variant<32>,survarium::std_allocator<vostok::variant<32> > > *this,
        vostok::variant<32> *__pos,
        unsigned int __n,
        const vostok::variant<32> *__x,
        const stlp_std::__false_type *__formal)
{
  int k; // [esp+C4h] [ebp-A4h]
  vostok::variant<32> *v6; // [esp+C8h] [ebp-A0h]
  int j; // [esp+CCh] [ebp-9Ch]
  vostok::variant<32> *v8; // [esp+D0h] [ebp-98h]
  vostok::variant<32> *v9; // [esp+D4h] [ebp-94h]
  int i; // [esp+E0h] [ebp-88h]
  vostok::variant<32> *v11; // [esp+E4h] [ebp-84h]
  vostok::variant<32> *v12; // [esp+E8h] [ebp-80h]
  int ii; // [esp+F0h] [ebp-78h]
  vostok::variant<32> *v14; // [esp+F4h] [ebp-74h]
  int n; // [esp+F8h] [ebp-70h]
  vostok::variant<32> *other; // [esp+FCh] [ebp-6Ch]
  vostok::variant<32> *v17; // [esp+100h] [ebp-68h]
  int m; // [esp+108h] [ebp-60h]
  vostok::variant<32> *__p; // [esp+10Ch] [ebp-5Ch]
  vostok::variant<32> *__val; // [esp+110h] [ebp-58h]
  vostok::variant<32> *M_finish; // [esp+124h] [ebp-44h]
  unsigned int v22; // [esp+128h] [ebp-40h]
  stlp_std::__false_type v23; // [esp+12Fh] [ebp-39h] BYREF
  vostok::variant<32> v24; // [esp+130h] [ebp-38h] BYREF
  stlp_std::priv::_Impl_vector<vostok::variant<32>,survarium::std_allocator<vostok::variant<32> > > *v26; // [esp+164h] [ebp-4h]

  v26 = this;
  if ( __x >= this->_M_start && __x < v26->_M_finish )
  {
    vostok::variant<32>::variant<32>(&v24, __x);
    v23 = 0;
    stlp_std::priv::_Impl_vector<vostok::variant<32>,survarium::std_allocator<vostok::variant<32>>>::_M_fill_insert_aux(
      v26,
      __pos,
      __n,
      &v24,
      &v23);
    vostok::variant<32>::~variant<32>(&v24);
  }
  else
  {
    v22 = v26->_M_finish - __pos;
    M_finish = v26->_M_finish;
    if ( v22 <= __n )
    {
      v12 = &v26->_M_finish[__n - v22];
      v11 = v26->_M_finish;
      for ( i = (int)(48 * (__n - v22)) / 48; i > 0; --i )
        stlp_std::_Copy_Construct<vostok::variant<32>>(v11++, __x);
      v26->_M_finish = v12;
      v9 = __pos;
      v8 = v26->_M_finish;
      for ( j = M_finish - __pos; j > 0; --j )
        stlp_std::_Copy_Construct<vostok::variant<32>>(v8++, v9++);
      v26->_M_finish += v22;
      v6 = __pos;
      for ( k = M_finish - __pos; k > 0; --k )
        vostok::variant<32>::operator=(v6++, __x);
    }
    else
    {
      __val = &v26->_M_finish[-__n];
      __p = v26->_M_finish;
      for ( m = __p - __val; m > 0; --m )
        stlp_std::_Copy_Construct<vostok::variant<32>>(__p++, __val++);
      v26->_M_finish += __n;
      v17 = M_finish;
      other = &M_finish[-__n];
      for ( n = other - __pos; n > 0; --n )
        vostok::variant<32>::operator=(--v17, --other);
      v14 = __pos;
      for ( ii = (int)(48 * __n) / 48; ii > 0; --ii )
        vostok::variant<32>::operator=(v14++, __x);
    }
  }
}
