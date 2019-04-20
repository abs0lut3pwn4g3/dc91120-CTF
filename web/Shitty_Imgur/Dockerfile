FROM python:3

WORKDIR /usr/src/app

COPY app ./
RUN pip install --no-cache-dir -r requirements.txt
EXPOSE 8080
RUN apt update && apt dist-upgrade --assume-yes && apt install sqlite3 --assume-yes
RUN chmod 777 site.db
RUN useradd env
RUN chown env -R /usr/src/app/
RUN chmod 766 -R /usr/src/app/site.db
CMD su env -c "gunicorn -w 4 -b 0.0.0.0:8080 application:app"
