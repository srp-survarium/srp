const vostok::fs_new::path_string_impl *__thiscall vostok::fs_new::path_string_impl::operator=<char const [1]>(
        vostok::fs_new::path_string_impl *this,
        vostok::fixed_string<16> *s)
{
  vostok::fixed_string<16>::operator=(s, &this->m_string);
  vostok::fs_new::path_string_impl::verify_self(this);
  return this;
}


const vostok::fs_new::path_string_impl *__thiscall vostok::fs_new::path_string_impl::operator=<char const *>(
        vostok::fs_new::path_string_impl *this,
        char **s)
{
  char *m_begin; // eax
  const char *v5; // [esp-4h] [ebp-8h]

  m_begin = this->m_string.m_begin;
  if ( this->m_string.m_begin != *s )
  {
    v5 = *s;
    this->m_string.m_end = m_begin;
    *m_begin = 0;
    vostok::buffer_string::operator+=(&this->m_string, v5);
  }
  return this;
}


const vostok::fs_new::path_string_impl *__thiscall vostok::fs_new::path_string_impl::operator=<vostok::platform_pointer_selector<char const,1>::helper>(
        vostok::fs_new::path_string_impl *this,
        const vostok::platform_pointer_selector<char const ,1>::helper *s)
{
  vostok::buffer_string::operator=(&this->m_string, s->pointer);
  vostok::fs_new::path_string_impl::verify_self(this);
  return this;
}


vostok::fs_new::native_path_string *__usercall vostok::fs_new::path_string_impl::operator+=<char>@<eax>(
        vostok::fs_new::native_path_string *this@<eax>,
        char *s@<edx>)
{
  *this->m_string.m_end++ = *s;
  *this->m_string.m_end = 0;
  return this;
}


char __thiscall vostok::fs_new::path_string_impl::operator==(
        vostok::fs_new::path_string_impl *this,
        vostok::fs_new::path_string_impl *other)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  return vostok::operator==(this, other);
}


BOOL __thiscall vostok::fs_new::path_string_impl::operator==(vostok::fs_new::path_string_impl *this, const char *path)
{
  return vostok::operator==(&this->m_string, path);
}


BOOL __thiscall vostok::fs_new::path_string_impl::operator!=(
        vostok::fs_new::path_string_impl *this,
        vostok::fs_new::path_string_impl *other)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  return vostok::operator==(this, other) == 0;
}


BOOL __thiscall vostok::fs_new::path_string_impl::operator!=(vostok::fs_new::path_string_impl *this, const char *path)
{
  return !vostok::operator==(&this->m_string, path);
}


char __thiscall vostok::fs_new::path_string_impl::operator[](vostok::fs_new::path_string_impl *this, unsigned int i)
{
  survarium::game_camera *v2; // ecx

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::weapon_user_dead_state::finalize(v2);
  return this->m_string.m_begin[i];
}
