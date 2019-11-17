XCSoar D-KMCH
=============
**This is a version adapted to our special needs. Use with caution.
Our adaptions are described in the following.**

Adaptions
---------
We forked XCSoar to add an NMEA-Sentence that describes fuel usage.
We use this for our Touring Motor Glider in an attempt to optimise
fuel efficiency.

The flow-meter we use counts "ticks" that are proportional to fuel use,
the NMEA-Sentence transmits the last registered tick-rate in ticks per second.
We intend to convert the tick-rate into the fuel rate in XCSoar, so there will
be a conversion factor that has to be input.

The NMEA-Sentence looks like the following:
``$PFLO,xxx.x*??`` where xxx.x is the flow-rate in ticks per second.

We determined our calibration factor to be 8600 ticks/liter.

Original README
---------------

.. image:: https://circleci.com/gh/XCSoar/XCSoar.svg?style=svg
    :target: https://circleci.com/gh/XCSoar/XCSoar

XCSoar is a tactical glide computer for Android, Linux, Mac OS X,
and Windows.

This file is aimed at developers. Developers should read the manual which 
can be found on the `XCSoar home page <https://xcsoar.org/discover/manual.html>`__.

Users can refer to the Users' Manual which, for the latest release, can be
downloaded via the `XCSoar home page <https://xcsoar.org/discover/manual.html>`__.

Getting the source
------------------

The XCSoar source code is managed with `git <http://git-scm.com/>`__.  It
can be downloaded with the following command::

 git clone --recursive git://github.com/XCSoar/XCSoar

To update your repository, type::

 git pull

For more information, please refer to the git documentation.


Compiling from source
---------------------

Please read the current Developers' Manual for detailed build instructions.

Submitting patches
------------------

Patches may be submitted using the Developers' mail list or GitHub. Refer to
chapter 3 of the current Developers' Manual for details of how to write and 
submit patches upstream.
