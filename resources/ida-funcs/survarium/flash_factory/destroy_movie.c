void __usercall survarium::flash_factory::destroy_movie(
        survarium::flash_movie *movie@<eax>,
        survarium::flash_factory *this)
{
  movie->m_movie_def = 0;
  movie->m_movie = 0;
  movie->m_handle = 0;
  operator delete(movie);
}
