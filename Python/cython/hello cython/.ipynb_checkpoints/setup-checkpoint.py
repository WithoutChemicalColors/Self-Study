{
 "cells": [
  {
   "cell_type": "code",
   "execution_count": 1,
   "metadata": {
    "collapsed": true
   },
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "Compiling hello.pyx because it changed.\n",
      "[1/1] Cythonizing hello.pyx\n"
     ]
    },
    {
     "name": "stderr",
     "output_type": "stream",
     "text": [
      "\n",
      "Error compiling Cython file:\n",
      "------------------------------------------------------------\n",
      "...\n",
      "{\n",
      " \"cells\": [\n",
      "  {\n",
      "   \"cell_type\": \"code\",\n",
      "   \"execution_count\": null,\n",
      "                     ^\n",
      "------------------------------------------------------------\n",
      "\n",
      "hello.pyx:5:22: undeclared name not builtin: null\n"
     ]
    },
    {
     "ename": "CompileError",
     "evalue": "hello.pyx",
     "output_type": "error",
     "traceback": [
      "\u001b[1;31m---------------------------------------------------------------------------\u001b[0m",
      "\u001b[1;31mCompileError\u001b[0m                              Traceback (most recent call last)",
      "\u001b[1;32m<ipython-input-1-b7e99485a4b6>\u001b[0m in \u001b[0;36m<module>\u001b[1;34m()\u001b[0m\n\u001b[0;32m      3\u001b[0m \u001b[1;33m\u001b[0m\u001b[0m\n\u001b[0;32m      4\u001b[0m setup(\n\u001b[1;32m----> 5\u001b[1;33m     \u001b[0mext_modules\u001b[0m \u001b[1;33m=\u001b[0m \u001b[0mcythonize\u001b[0m\u001b[1;33m(\u001b[0m\u001b[1;34m\"hello.pyx\"\u001b[0m\u001b[1;33m)\u001b[0m\u001b[1;33m\u001b[0m\u001b[0m\n\u001b[0m\u001b[0;32m      6\u001b[0m )\n",
      "\u001b[1;32m~\\Anaconda3\\lib\\site-packages\\Cython\\Build\\Dependencies.py\u001b[0m in \u001b[0;36mcythonize\u001b[1;34m(module_list, exclude, nthreads, aliases, quiet, force, language, exclude_failures, **options)\u001b[0m\n\u001b[0;32m   1037\u001b[0m     \u001b[1;32mif\u001b[0m \u001b[1;32mnot\u001b[0m \u001b[0mnthreads\u001b[0m\u001b[1;33m:\u001b[0m\u001b[1;33m\u001b[0m\u001b[0m\n\u001b[0;32m   1038\u001b[0m         \u001b[1;32mfor\u001b[0m \u001b[0margs\u001b[0m \u001b[1;32min\u001b[0m \u001b[0mto_compile\u001b[0m\u001b[1;33m:\u001b[0m\u001b[1;33m\u001b[0m\u001b[0m\n\u001b[1;32m-> 1039\u001b[1;33m             \u001b[0mcythonize_one\u001b[0m\u001b[1;33m(\u001b[0m\u001b[1;33m*\u001b[0m\u001b[0margs\u001b[0m\u001b[1;33m)\u001b[0m\u001b[1;33m\u001b[0m\u001b[0m\n\u001b[0m\u001b[0;32m   1040\u001b[0m \u001b[1;33m\u001b[0m\u001b[0m\n\u001b[0;32m   1041\u001b[0m     \u001b[1;32mif\u001b[0m \u001b[0mexclude_failures\u001b[0m\u001b[1;33m:\u001b[0m\u001b[1;33m\u001b[0m\u001b[0m\n",
      "\u001b[1;32m~\\Anaconda3\\lib\\site-packages\\Cython\\Build\\Dependencies.py\u001b[0m in \u001b[0;36mcythonize_one\u001b[1;34m(pyx_file, c_file, fingerprint, quiet, options, raise_on_failure, embedded_metadata, progress)\u001b[0m\n\u001b[0;32m   1159\u001b[0m     \u001b[1;32mif\u001b[0m \u001b[0many_failures\u001b[0m\u001b[1;33m:\u001b[0m\u001b[1;33m\u001b[0m\u001b[0m\n\u001b[0;32m   1160\u001b[0m         \u001b[1;32mif\u001b[0m \u001b[0mraise_on_failure\u001b[0m\u001b[1;33m:\u001b[0m\u001b[1;33m\u001b[0m\u001b[0m\n\u001b[1;32m-> 1161\u001b[1;33m             \u001b[1;32mraise\u001b[0m \u001b[0mCompileError\u001b[0m\u001b[1;33m(\u001b[0m\u001b[1;32mNone\u001b[0m\u001b[1;33m,\u001b[0m \u001b[0mpyx_file\u001b[0m\u001b[1;33m)\u001b[0m\u001b[1;33m\u001b[0m\u001b[0m\n\u001b[0m\u001b[0;32m   1162\u001b[0m         \u001b[1;32melif\u001b[0m \u001b[0mos\u001b[0m\u001b[1;33m.\u001b[0m\u001b[0mpath\u001b[0m\u001b[1;33m.\u001b[0m\u001b[0mexists\u001b[0m\u001b[1;33m(\u001b[0m\u001b[0mc_file\u001b[0m\u001b[1;33m)\u001b[0m\u001b[1;33m:\u001b[0m\u001b[1;33m\u001b[0m\u001b[0m\n\u001b[0;32m   1163\u001b[0m             \u001b[0mos\u001b[0m\u001b[1;33m.\u001b[0m\u001b[0mremove\u001b[0m\u001b[1;33m(\u001b[0m\u001b[0mc_file\u001b[0m\u001b[1;33m)\u001b[0m\u001b[1;33m\u001b[0m\u001b[0m\n",
      "\u001b[1;31mCompileError\u001b[0m: hello.pyx"
     ]
    }
   ],
   "source": [
    "from distutils.core import setup\n",
    "from Cython.Build import cythonize\n",
    "\n",
    "setup(\n",
    "    ext_modules = cythonize(\"hello.pyx\")\n",
    ")"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": null,
   "metadata": {},
   "outputs": [],
   "source": []
  }
 ],
 "metadata": {
  "kernelspec": {
   "display_name": "Python 3",
   "language": "python",
   "name": "python3"
  },
  "language_info": {
   "codemirror_mode": {
    "name": "ipython",
    "version": 3
   },
   "file_extension": ".py",
   "mimetype": "text/x-python",
   "name": "python",
   "nbconvert_exporter": "python",
   "pygments_lexer": "ipython3",
   "version": "3.6.4"
  }
 },
 "nbformat": 4,
 "nbformat_minor": 2
}
